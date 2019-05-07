pos = [-1 -1 2 2];
rectangle('Position',pos,'Curvature',[1 1])
axis equal
pos = [-1 -1 2 2];
rectangle('Position',pos)
inside=0;
total=0;
for i=0:1:10000
  posX = -1 +(1+1)*rand(1,1);
  posY = -1+(1+1)*rand(1,1);
  hold on;
  plot([posX],[posY],'r.')
  total+=1;
  if (power(posX,2)+power(posY,2)<=1)
    inside+=1;
  endif
endfor
PI=4*(inside/total)