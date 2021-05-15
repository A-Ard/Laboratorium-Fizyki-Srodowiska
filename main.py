import os


data=open('data.txt', 'r')
uv_levels=open('uv_levels.txt','a')
uv_volts=open('uv_volts.txt','a')
uv_intensities=open('uv_intensities.txt','a')
amb_levels=open('amb_levels.txt','a')
amb_volts=open('amb_volts.txt','a')
amb_densities=open('amb_densities.txt','a')
for i in range(270):
    hour=data.readline()
    minute=data.readline()
    second=data.readline()
    space1=data.readline()
    tag1=data.readline()
    uvlevel=data.readline()
    uv_levels.write(uvlevel)
    tag2=data.readline()
    outvoltuv=','.join(data.readline().split('.'))
    uv_volts.write(outvoltuv)
    tag3=data.readline()
    uvintensity=','.join(data.readline().split('.'))
    uv_intensities.write(uvintensity)
    unituv=data.readline()
    space2=data.readline()
    tag4=data.readline()
    amblevel=data.readline()
    amb_levels.write(amblevel)
    tag5=data.readline()
    outvoltamb=','.join(data.readline().split('.'))
    amb_volts.write(outvoltamb)
    tag6=data.readline()
    ambdensity=','.join(data.readline().split('.'))
    amb_densities.write(ambdensity)
    unitamb=data.readline()
    space3=data.readline()
    print(i)


data.close()
uv_levels.close()
uv_volts.close()
uv_intensities.close()
amb_levels.close()
amb_volts.close()
amb_densities.close()
print('done')







