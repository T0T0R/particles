from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import plotly
print(plotly.__version__)  # version >1.9.4 required
from plotly.graph_objs import Scatter3d, Layout

#import numpy as np

MyFile = open("../datas.txt", "r");
print("File opened...");

rawFile = MyFile.read();
rawLines = rawFile.split("\n");
MyFile.close();
print("File closed.");

simInfos = rawLines[0].split("\t");
nbTemps = int(simInfos[0]);
nbPart = int(simInfos[1]);

particles=[]
timing = []
times = []

for line in rawLines[1:]:
    #Extract coordinates without timings
    timing.append(   (str(line[1:]).split("\t"))[1:]      );
    times.append( (str(line[1:]).split("\t"))[0]  )


#creating this table:
#particles = [ particle0[ coordinatesX[t0, t1...], coordinatesY[t0, t1...]..., particle1[ coordinatesX[t0, t1...], coordinatesY[t0, t1...]... ]... ]

for iParticle in range(nbPart):
    print("Reading particle " + str(iParticle+1) + " / " +str(nbPart) );
    emptyList1 =[]
    particles.append(emptyList1);
    
    for coordinate in range(3):
        emptyList2 =[]
        particles[iParticle].append(emptyList2);
        
        for timestep in range(nbTemps):
            particles[iParticle][coordinate].append(    float(  (timing[timestep][iParticle].split(";")) [coordinate]  ) )
            


fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

plotlyDatas = []
i=0

print("Creating graph tables...");
for iParticle in particles:
    print("Adding particle " + str(i+1) + " / " +str(nbPart) );
    #ax.plot(iParticle[0], iParticle[1], iParticle[2])#For matplotlib if plotly doesn't work
    plotlyDatas.append(Scatter3d(x=iParticle[0], y=iParticle[1], z=iParticle[2], customdata=times, hovertext="Particle "+str(i), hoverinfo="text", mode="lines"));#For plotly
    i+=1;
    

print("Generating graph...");
plotly.offline.plot({#For plotly
    "data": plotlyDatas,
    "layout": Layout(
        title="Output"
    )
    })



#plt.show();#For matplotlib if plotly doesn't work