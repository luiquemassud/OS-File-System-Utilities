make:	myls	mysearch	mystat	mytail

myls:	myls-massud.c
	gcc	-o	myls	myls-massud.c
mysearch:	mysearch-massud.c
	gcc	-o	mysearch	mysearch-massud.c
mytail:	mytail-massud.c
	gcc	-o	mytail	mytail-massud.c
mystat:	mystat-massud.c
	gcc	-o	mystat	mystat-massud.c