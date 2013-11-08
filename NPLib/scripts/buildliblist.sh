# *****************************************************************************
# * Copyright (C) 2009   this file is part of the NPTool Project              *
# *                                                                           *
# * For the licensing terms see $NPTOOL/Licence/NPTool_Licence                *
# * For the list of contributors see $NPTOOL/Licence/Contributors             *
# *****************************************************************************/

# *****************************************************************************
# * Original Author: N. de Sereville  contact address: deserevi@ipno.in2p3.fr *
# *                                                                           *
# * Creation Date  : 16/11/10                                                 *
# * Last update    :                                                          *
# *---------------------------------------------------------------------------*
# * Decription: This script builds the liblist file which is used when linking*
# *             the NPS and NPA binary files.                                 * 
# *---------------------------------------------------------------------------*
# * Comment:                                                                  *
# *                                                                           *
# *                                                                           *
# *****************************************************************************

#! /bin/bash

echo " + Creating liblist file....."

# output file
outfile="liblist"

# if output file exists delete it
#if [ -e $outfile ] ; then 
#   rm $outfile 
#fi ;

# create output file
printf "#! /bin/bash\n" > $outfile
printf "#\n" >> $outfile
printf "# WARNING:\n" >> $outfile
printf "#    This file is automatically generated when NPLib libraries are built through the make command.\n" >> $outfile
printf "#    If you modify this file by hand, changes won't persist the next time you compile NPLib.\n" >> $outfile
printf "#\n" >> $outfile
printf "echo -L$NPTOOL/NPLib/lib" >> $outfile
chmod a+x $outfile

# loop on *.so files in lib/ directory
for file in lib/*.so
do
   if [ -f $file ] ; then 
      # remove .so extension
      name=${file%\.*}
      # replace "lib/lib" pattern by "-l"
      name=$(printf $name | sed -e "s/lib\/lib/-l/g")
      printf " $name " >> $outfile
   fi ;
done
