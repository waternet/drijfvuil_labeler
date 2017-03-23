for f in ./*.MP4
do
   filename=${f#*./}
   echo $filename
	
   ffmpeg -i $f -r 1 -f image2 $filename-%05d.png
done
