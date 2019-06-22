
data1 = read.csv("data_1.csv", header = TRUE) 
data2 = read.csv("data_2.csv", header = TRUE) 
data3 = read.csv("data_3.csv", header = TRUE) 
data4 = read.csv("data_4.csv", header = TRUE) 


mean_1_cores = colMeans(data1)
mean_2_cores = colMeans(data2)
mean_3_cores = colMeans(data3)
mean_4_cores = colMeans(data4)


speedup_1 = c(1:10)*0+1
speedup_2 = mean_1_cores / mean_2_cores
speedup_3 = mean_1_cores / mean_3_cores
speedup_4 = mean_1_cores / mean_4_cores
Cores = c(1:4)

Speed_up = rbind(speedup_1, speedup_2, speedup_3, speedup_4)
Speed_up_ideal = cbind(Speed_up, c(1:4))

x11()
matplot(Speed_up_ideal, type = "l", xlab = "Cores", ylab = "Speedup")
for(i in c(1:11)){
  points(Cores, Speed_up_ideal[,i], pch=16, col = "dark red")
}
grid()


library(xlsx)
write.xlsx(Speed_up_ideal, "speedup.xlsx")

