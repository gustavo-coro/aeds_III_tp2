#------Teste 1-------
fb1 <- read.csv("solFB_teste1.csv", header = TRUE, 
                  sep = ";", 
                  dec = ".")
View(fb1)
summary(fb1)
plot(fb1$entrada_saida ~ fb1$entrada , xlab = 'Entrada', ylab = 'Tempo (microsegundos)')

pd1 <- read.csv("solPD_teste1.csv", header = TRUE, 
                sep = ";", 
                dec = ".")
View(pd1)
summary(pd1)
plot(pd1$entrada_saida ~ pd1$entrada , xlab = 'Entrada', ylab = 'Tempo (microsegundos)')

#------Teste 2-------
fb2 <- read.csv("solFB_teste2.csv", header = TRUE, 
                sep = ";", 
                dec = ".")
View(fb2)
summary(fb2)
plot(fb2$entrada_saida ~ fb2$entrada , xlab = 'Entrada', ylab = 'Tempo (microsegundos)')

pd2 <- read.csv("solPD_teste2.csv", header = TRUE, 
                sep = ";", 
                dec = ".")
View(pd2)
summary(pd2)
plot(pd2$entrada_saida ~ pd2$entrada , xlab = 'Entrada', ylab = 'Tempo (microsegundos)')

#------Teste 3-------
fb3 <- read.csv("solFB_teste3.csv", header = TRUE, 
                sep = ";", 
                dec = ".")
View(fb3)
summary(fb3)
plot(fb3$entrada_saida ~ fb3$entrada , xlab = 'Entrada', ylab = 'Tempo (microsegundos)')

pd3 <- read.csv("solPD_teste3.csv", header = TRUE, 
                sep = ";", 
                dec = ".")
View(pd3)
summary(pd3)
plot(pd3$entrada_saida ~ pd3$entrada , xlab = 'Entrada', ylab = 'Tempo (microsegundos)')


#-----Testes Grande PD--------
pdGrande1 <- read.csv("testeGrandePD.csv", header = TRUE, 
                sep = ";", 
                dec = ".")
View(pdGrande1)
summary(pdGrande1)
plot(pdGrande1$entrada_saida ~ pdGrande1$entrada , xlab = 'Entrada', ylab = 'Tempo (microsegundos)')

pdGrande2 <- read.csv("testeGrandePD2.csv", header = TRUE, 
                      sep = ";", 
                      dec = ".")
View(pdGrande2)
summary(pdGrande2)
plot(pdGrande2$entrada_saida ~ pdGrande2$entrada , xlab = 'Entrada', ylab = 'Tempo (microsegundos)')

pdGrande3 <- read.csv("testeGrandePD3.csv", header = TRUE, 
                      sep = ";", 
                      dec = ".")
View(pdGrande3)
summary(pdGrande3)
plot(pdGrande3$entrada_saida ~ pdGrande3$entrada , xlab = 'Entrada', ylab = 'Tempo (microsegundos)')

pdGrande4 <- read.csv("testeGrandePD4.csv", header = TRUE, 
                      sep = ";", 
                      dec = ".")
View(pdGrande4)
summary(pdGrande4)
plot(pdGrande4$entrada_saida ~ pdGrande4$entrada , xlab = 'Entrada', ylab = 'Tempo (microsegundos)')

