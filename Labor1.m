%% Aufgabe 1
%Summe a:
n_a = 0:1000;

%for schleife:
sa_loop = 0;
 for k = 0:1000
    sa_loop = sa_loop + k^2;
 end

%vektorisiert:
sa_vec = sum(n_a.^2);     %.^ für elementarweises quadrieren

%Summe b:
n_b = 3:1000;

%for schleife:
sb_loop = 0;
for k = 3:1000
    sb_loop = sb_loop + 1/k;
end

%vektorisiert:
sb_vec = sum(1./n_b);    % für elementarweise

%Summe c:
n_c = 0:1000;

%for schleife:
sc_loop = 0;
for k = 0:1000
    sc_loop = sc_loop + sin((k*pi)/14);
end

%vektorisiert:
sc_vec = sum(sin(n_c * pi/14));


fprintf('Ergebnis (a): Loop = %.0f, Vektor = %.0f\n', sa_loop, sa_vec);
fprintf('Ergebnis (b): Loop = %.0f, Vektor = %.0f\n', sb_loop, sb_vec);
fprintf('Ergebnis (c): Loop = %.0f, Vektor = %.0f\n', sc_loop, sc_vec);

%% Aufgabe 2

%Definitionsbereich festlegen
x = linspace(0.01, 20, 1000);

f = 5 * exp(x/3);
g = 0.1 * x.^4;

%f(x):
figure('Name', 'Funktion f(x)');
tiledlayout(2,2);
%Erstellt ein neues leeres Grafikfenster

% 1. Lineare Skala
nexttile; plot(x, f); grid on;
title('Lineare Skala'); xlabel('x'); ylabel('f(x)');

% 2. Logarithmische x-Achse
nexttile; semilogx(x, f); grid on;
title('log. x-Achse'); xlabel('x'); ylabel('f(x)');

% 3. Logarithmische y-Achse (f(x) wird hier zur Geraden)
nexttile; semilogy(x, f); grid on;
title('log. y-Achse'); xlabel('x'); ylabel('f(x)');

% 4. Doppelt logarithmisch
nexttile; loglog(x, f); grid on;
title('log-log-Skala'); xlabel('x'); ylabel('f(x)');

%g(x):
figure('Name', 'Funktion g(x)');
tiledlayout(2,2);

% 1. Lineare Skala
nexttile; plot(x, g); grid on;
title('Lineare Skala'); xlabel('x'); ylabel('g(x)');

% 2. Logarithmische x-Achse
nexttile; semilogx(x, g); grid on;
title('log. x-Achse'); xlabel('x'); ylabel('g(x)');

% 3. Logarithmische y-Achse
nexttile; semilogy(x, g); grid on;
title('log. y-Achse'); xlabel('x'); ylabel('g(x)');

% 4. Doppelt logarithmisch  (g(x) wird hier zur Geraden)
nexttile; loglog(x, g); grid on;
title('log-log-Skala'); xlabel('x'); ylabel('g(x)');

%% Aufgabe 3

% Definitionsbereich festlegen (Vektor x)
x = linspace(0, 2*pi, 500);
% Originale Sinusfunktion berechnen
y_sin = sin(x);

% Plotten vorbereiten
figure
plot(x, y_sin, 'w--', 'LineWidth', 2); %w: weiß, -- gestrichelt
hold on;

% Taylorpolynome für N = 1, 2, 3, 6 berechnen und plotten
N_werte = [1, 2, 3, 6];
for N = N_werte
    y_taylor = sinTaylor(x, N);
    plot(x, y_taylor, 'LineWidth', 1.5);
end

% Beschriftung und Legende
grid on;
title('Approximation von sin(x) durch Taylorpolynome');
xlabel('x');
ylabel('y');
ylim([-1.5, 1.5]); % Achsen skalieren, damit der Plot übersichtlich bleibt
legend('sin(x)', 'N=1', 'N=2', 'N=3', 'N=6', 'Location', 'southwest');
hold off;