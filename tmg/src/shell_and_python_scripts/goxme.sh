


while sleep 2

do
prefix=trades
suffix=$(date +%s)  # The "+%s" option to 'date' is GNU-specific.
filename=$prefix.$suffix.json

curl https://mtgox.com/code/data/getTrades.php -o json_files/$filename
file=json_files/$filename


sed -e 's/\[/{somedata:[/' -i $file
sed -e 's/\]/]}/' -i $file


python -c 'import work; work.removeDocuments()'

mongoimport --host localhost --db test --collection trades --type json --file $file
python stats.py
eog --new-instance test.png
done
