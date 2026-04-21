function p = sinTaylor(x, N)
    % Initialisierung des Ergebnisvektors mit Nullen in der Größe von x
    p = zeros(size(x));
    
    % Schleife zur Berechnung der Summe von k = 1 bis N
    for k = 1:N
        zaehler = (-1)^(k+1);
        nenner = factorial(2*k - 1);
        potenz = x.^(2*k - 1); % Vektorisierte Potenzrechnung
        
        % Term zum Gesamtpolynom addieren
        p = p + (zaehler / nenner) * potenz;
    end
end