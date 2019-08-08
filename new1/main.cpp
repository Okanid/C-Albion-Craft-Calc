#include <iostream>

using namespace std;

class itemsCount {
private:
    int resorce = 0;
    int price = 0;
    int resorceCount = 0;
public:
    //формула для расчетак ресурсов
    int resorceFunc(){
        int itemCount = 0;

        int count1[10];
        int oneResource = 0;
        int oneCoin = 0;
        int countCoin[10];
        char answer = 'q';


        cout << "Сколько вещей хотите скрафтить:\t ";
        cin >> itemCount;
        cout << "Сколько видов ресурсов необходимо для вашего крафта:\t ";
        cin >> resorceCount;
        while(resorceCount > 5){
            cout << "Недопустимое количество!!!\nВведите не более 5: ";
            cin >> resorceCount;
        }

        cout << "Вы знаете примерную стоимость за единицу каждого ресурса?(Y/N)" << endl;
        cin >> answer;
        while(answer != 'Y' && answer != 'N' && answer != 'y' && answer != 'n'){
            cout << "Неверный символ" << endl;
            cin >> answer;
        }

        if(answer == 'y' || answer == 'Y'){
            for (int i=1; i <= resorceCount; i++){
            cout << "Цена единицы " << i << " ресурса:\t ";
            cin >> countCoin[i];
            oneCoin += countCoin[i];
            }
        }

        for (int i=1; i <= resorceCount; i++){
            cout << "Количество " << i << " ресурса на единицу вещи:\t ";
            cin >> count1[i];
            oneResource += count1[i];
        }

        cout << "\nДля " << itemCount << " вещей вам потебуется:\n";
        for (int i = 1; i <= resorceCount; i++){
            cout << count1[i] * itemCount << " единиц " << i << " ресурса\n";
            if(answer == 'y' || answer == 'Y'){
            cout << " и " << countCoin[i] * count1[i] * itemCount << " серебра." << endl;
            }
        }

        return 0;
    }
    //расчет сколько выйдет вещей с имеющихся ресурсов
    int itemsFunc(){
        int resorceTypesCount[5];
        int allResorceTypeCount[5];
        int resorceTypes = 0;
        int sum[10];
        int x=0;
        int y = 0;
        cout << "Сколько видов ресурсов нужно для создания 1 вещи?\t";
        cin >> resorceTypes;
        cout << endl;
        while(resorceTypes > 5){
            cout << "Недопустимое количество!!!\nВведите не более 5: ";
            cin >> resorceTypes;
        }
        for (int i=1;i<=resorceTypes ;i++ ){
            cout << "Сколько необходимо ресурсов " << i << " вида на одну вещь?\t";// i1 = 12, i2 = 20;
            cin >> resorceTypesCount[i];
        }
        for (int i=1;i<=resorceTypes ;i++ ){
            cout << "\nСколько у вас ресурсов " << i << " вида?\t";
            cin >> allResorceTypeCount[i]; //i1 = 100 i2 = 200
        }
        for (int i=1;i<=resorceTypes ;i++ ){
                sum[i] = allResorceTypeCount[i] / resorceTypesCount[i];
                if(i==1)
                    x = sum[i];
                else
                    y=sum[i];
                if(i != resorceTypes)
                    cout << "Из " << allResorceTypeCount[i] << " ресурсов " << i << " вида и \n";
                else{
                    if(x < y)
                        cout << "Из " << allResorceTypeCount[i] << " ресурсов " << i << " вида получится " << x << " вещей.";
                    else
                        cout << "Из " << allResorceTypeCount[i] << " ресурсов " << i << " вида получится " << y << " вещей.";
                }
        }
        return 0;
    }
};

class myMainClass //выбор что надо подсчитать
{
public:
    int whatAnswer = 0;
    int askFunc(){
        cout << "Подсчитать количество ресурсов или вещей? (1/2)\t";
        while(whatAnswer > 2 || whatAnswer < 1){
            cin >> whatAnswer;
            if(whatAnswer == 1){
                itemsCount items;
                items.resorceFunc();
            }else if (whatAnswer == 2){
                itemsCount items;
                items.itemsFunc();
            }else
                cout << "\n\nМожно ввести только 1 или 2\n\n";
        }
        return whatAnswer;
    }
private:

};


int main()
{
    setlocale(LC_ALL, "Russian");
    bool repeat = true;
    char no = 'y';
    while(repeat == true){
        if(no == 'y'){
            myMainClass itemsCalc;
            itemsCalc.askFunc();
        }
        cout << "\n\nПовторить вычисления?(Y/N)";
        cin >> no;
        if(no == 'N' || no == 'n')
            repeat = false;
        else if (no == 'y' || no == 'Y')
            repeat = true;
        else
            cout << "\nВведите N или Y\n\n";
    }
    return 0;
}
