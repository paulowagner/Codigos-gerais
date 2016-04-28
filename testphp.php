<!DOCTYPE html>
<html>
<html>
  <head>
    <title>Aprendendo!!</title>
  </head>
	<body>
        <p>
          <?php
				if(date('m')==1)
					echo "Janeiro";
				elseif(date('m')==2)
					echo "Fevereiro";
				elseif(date('m')==3)
					echo "Março";
				elseif(date('m')==4)
					echo "Abril";
				elseif(date('m')==5)
					echo "Maio";
				elseif(date('m')==6)
					echo "Junho";
				elseif(date('m')==7)
					echo "Julio";
				elseif(date('m')==8)
					echo "Agosto";
				elseif(date('m')==9)
					echo "Setembro";
				elseif(date('m')==10)
					echo "Outubro";
				elseif(date('m')==11)
					echo "Novembro";
				else
					echo "Dezembro";
				echo '<br />';
		            	echo " Hoje eh dia " . date('m');
				echo '<br />';
				echo " Agora sao " . date('H:i:s');
				echo '<br />';
				<table>
					<table border="1">
					<tr>
						<th>Dom</th>
						<th>Seg</th>
						<th>Ter</th>
						<th>Qua</th>
						<th>Qui</th>
						<th>Sex</th>
						<th>Sáb</th>

					</tr>
				</table>
          ?>
        </p>
	</body>
</html>
