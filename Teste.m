
teste=[7200, 6100, 7300, 7300, 8000, 7400, 7300, 7300, 8000, 6700, 8300];
%Amostra de 12 elementos
canister=[5250, 5625, 5900, 5900, 5700, 6050, 5800, 6000, 5875, 6100, 5850, 6600];
%Define as posições onde será gerado o gráfico posição X, posição Y, Largura, Altura
posicao=[200,200,700,300];
%Define os limites inferiores e superiores para o eixo X e Y
eixo=([0.5, 1.5, 5200, 8500]);
%Gera uma figura para que possamos colocar os dois gráficos dentro dela
figure('Position',posicao);
%Limpa a área onde serão plotados os gráficos
clf;
%Define que o primeiro gráfico estará numa matriz 1(linha)x2(coluna) e na posição 1
subplot(1,2,1);
%Plota o gráfico
boxplot(teste);
%Adiciona um título ao gráfico
title('Boxplot Teste');
%Coloca uma legenda no eixo X
xlabel('Teste');
%Corrige a escala do eixo
axis(eixo);
%Define que o segundo gráfico estará numa matriz 1(linha)x2(coluna) e na posição 2
subplot(1,2,2);
%Plota o gráfico
boxplot(canister);
%Adiciona um título ao gráfico
title('Boxplot Canister');
%Coloca uma legenda no eixo X
xlabel('Canister');
%Corrige a escala do eixo
axis(eixo);
disp ('Fast Fourier Transform:');
tempo = input('Digite o tempo de gravação: '); 

disp ('Start falando.');
objeto = record (tempo,8000);

disp ('Fim da gravação.');

% Reproduzir a gravação.
%play (objeto);

%Dados da loja em matriz de precisão dupla.
myRecording = getaudiodata (objeto);

% Traçar a forma de onda.

%plot (myRecording);
%title('Grafico da musica','color','blue');
%xlabel('Segundos','color','blue');
%ylabel('Hz','color','blue');

mknod /dev/dsp c 14 3 && chgrp audio /dev/dsp && chmod g+w /dev/dsp 