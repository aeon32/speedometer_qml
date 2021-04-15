# -*- coding: utf8 -*-
import sys
import xml.dom.minidom
import xml.dom
import xml.parsers.expat 
import os
import types
import string
import codecs

def relpath(curdir,filename):
	common_prefix=os.path.realpath(os.path.commonprefix([curdir,filename]))
	head_cur=curdir
	res=''
        while head_cur!=common_prefix:
	  res=res+'../';
	  head_cur,tail_cur=os.path.split(head_cur)
	
	return res+string.replace(filename,common_prefix+'/','',1)
	  
	     


def main(argv):
    curdir=os.path.dirname(os.path.realpath(__file__))
    curdir=unicode(curdir, 'utf-8')
    filelist=os.listdir(curdir)
    for i in filelist:
        name,ext=os.path.splitext(i)
        if ext==".cbp":
            try:
              cb_project = xml.dom.minidom.parse(os.path.join(curdir,i))
              options = cb_project.getElementsByTagName('Option')
              def process_option(option):
                  if option.hasAttribute('virtualFolders'):
		    vfolder_value = option.getAttribute('virtualFolders')
		    if string.find(vfolder_value,'CMake Files')!=-1:
		      option.parentNode.removeChild(option)
		      option.unlink()
                  elif option.hasAttribute('virtualFolder'):
		    vfolder_value = option.getAttribute('virtualFolder')
		    if string.find(vfolder_value,'CMake Files')!=-1:
		      option.parentNode.parentNode.removeChild(option.parentNode)
		      option.parentNode.unlink()
		    
	      map(process_option,options)
              
              units=cb_project.getElementsByTagName('Unit')
              def process_unit(unit):
                  parentNode=unit.parentNode;
                  if not(type(parentNode) is types.NoneType) and parentNode.nodeName=='Project' and unit.hasAttributes():
                      if unit.hasAttribute('filename'):
                          unit_value=unit.getAttribute('filename')
                          new_unit_value= relpath(curdir,os.path.realpath(unit_value))
                          unit.setAttribute('filename',new_unit_value)
			  if string.find(unit_value,'libpq')!=-1:
			     parentNode.removeChild(unit)
			     unit.unlink()
              map(process_unit,units )
              with codecs.open(os.path.join(curdir,i),'w','utf-8') as out:
                  cb_project.writexml(out)
	      
            except xml.parsers.expat.ExpatError:
                print "Error processing %(filename)s" % {"filename":i}
              
    
    pass



    
if __name__=="__main__":
    #print relpath(os.path.dirname(os.path.realpath(__file__)),'/home/projects/esvp/ui/cstartdialog.ui');	
    main(sys.argv)



    
