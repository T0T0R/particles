from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import plotly
print(plotly.__version__)  # version >1.9.4 required
from plotly.graph_objs import Scatter3d, Layout

#import numpy as np

MyFile = open("../datas.txt", "r");
rawFile = MyFile.read();
rawLines = rawFile.split("\n");
MyFile.close();

simInfos = rawLines[0].split("\t");
nbTemps = int(simInfos[0]);
nbPart = int(simInfos[1]);

particles=[]
timing = []

for line in rawLines[1:]:
    #Extract coordinates without timings
    timing.append(   (str(line[1:]).split("\t"))[1:]      );


#creating this table:
#particles = [ particle0[ coordinatesX[t0, t1...], coordinatesY[t0, t1...]..., particle1[ coordinatesX[t0, t1...], coordinatesY[t0, t1...]... ]... ]

for iParticle in range(nbPart):
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

for iParticle in particles:
    ax.plot(iParticle[0], iParticle[1], iParticle[2])#For matplotlib if plotly doesn't work
    plotlyDatas.append(Scatter3d(x=iParticle[0], y=iParticle[1], z=iParticle[2], hoverinfo="none", mode="lines"))#For plotly
    


plotly.offline.plot({#For plotly
    "data": plotlyDatas,
    "layout": Layout(
        title="Output"
    )
    })



plt.show();#For matplotlib if plotly doesn't work