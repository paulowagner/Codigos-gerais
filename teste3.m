%Grave a sua voz por 5 segundos.
clc
disp ('Fast Fourier Transform:');
tempo = input('Digite o tempo de gravação: '); 
objeto = audiorecorder;
disp ('Start falando.');
recordblocking (objeto, tempo);
disp ('Fim de gravação');

%Dados em matriz.
matriz = getaudiodata (objeto);

%transformada
NFFT = 2^nextpow2(L); % Next power of 2 from length of y
Y = fft(matriz,NFFT)/L;
f1 = 8000/2*linspace(0,1,NFFT/2+1);
f2 = 200/2*linspace(0,1,NFFT/2+1);

%Define as posições onde será gerado o gráfico posição X, posição Y, Largura, Altura
posicao=[200,200,700,300];
%Define os limites inferiores e superiores para o eixo X e Y
eixo1=([0,4000, 0, 0.02]);
%Define os limites inferiores e superiores para o eixo X e Y
eixo2=([0,4000, 0, 1]);
%Gera uma figura para que possamos colocar os dois gráficos dentro dela
figure('Position',posicao);
%Limpa a área onde serão plotados os gráficos
clf;

%Define que o primeiro gráfico estará numa matriz 1(linha)x2(coluna) e na posição 1
subplot(1,2,1);
%Grafico de harmonico.
plot(f1,2*abs(Y(1:NFFT/2+1)),f2,2*abs(Y(1:NFFT/2+1))) 
title('Harmonicos:')
xlabel('Frequencia (Hz).')
ylabel('|Y(f)|')
%Corrige a escala do eixo
axis(eixo1);

%Define que o primeiro gráfico estará numa matriz 1(linha)x2(coluna) e na posição 1
subplot(1,2,2);
% Traçar a forma de onda.
plot (matriz);
title('Grafico da musica','color','blue');
xlabel('Segundos','color','blue');
ylabel('Hz','color','blue');
%Corrige a escala do eixo
axis(eixo2);

% Reproduzir a gravação.
play(objeto);
