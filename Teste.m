
teste=[7200, 6100, 7300, 7300, 8000, 7400, 7300, 7300, 8000, 6700, 8300];
%Amostra de 12 elementos
canister=[5250, 5625, 5900, 5900, 5700, 6050, 5800, 6000, 5875, 6100, 5850, 6600];
%Define as posi��es onde ser� gerado o gr�fico posi��o X, posi��o Y, Largura, Altura
posicao=[200,200,700,300];
%Define os limites inferiores e superiores para o eixo X e Y
eixo=([0.5, 1.5, 5200, 8500]);
%Gera uma figura para que possamos colocar os dois gr�ficos dentro dela
figure('Position',posicao);
%Limpa a �rea onde ser�o plotados os gr�ficos
clf;
%Define que o primeiro gr�fico estar� numa matriz 1(linha)x2(coluna) e na posi��o 1
subplot(1,2,1);
%Plota o gr�fico
boxplot(teste);
%Adiciona um t�tulo ao gr�fico
title('Boxplot Teste');
%Coloca uma legenda no eixo X
xlabel('Teste');
%Corrige a escala do eixo
axis(eixo);
%Define que o segundo gr�fico estar� numa matriz 1(linha)x2(coluna) e na posi��o 2
subplot(1,2,2);
%Plota o gr�fico
boxplot(canister);
%Adiciona um t�tulo ao gr�fico
title('Boxplot Canister');
%Coloca uma legenda no eixo X
xlabel('Canister');
%Corrige a escala do eixo
axis(eixo);
disp ('Fast Fourier Transform:');
tempo = input('Digite o tempo de grava��o: '); 

disp ('Start falando.');
objeto = record (tempo,8000);

disp ('Fim da grava��o.');

% Reproduzir a grava��o.
%play (objeto);

%Dados da loja em matriz de precis�o dupla.
myRecording = getaudiodata (objeto);

% Tra�ar a forma de onda.

%plot (myRecording);
%title('Grafico da musica','color','blue');
%xlabel('Segundos','color','blue');
%ylabel('Hz','color','blue');

mknod /dev/dsp c 14 3 && chgrp audio /dev/dsp && chmod g+w /dev/dsp 