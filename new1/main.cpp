#include <iostream>

using namespace std;

class itemsCount {
private:
    int resorce = 0;
    int price = 0;
    int resorceCount = 0;
public:
    //������� ��� �������� ��������
    int resorceFunc(){
        int itemCount = 0;

        int count1[10];
        int oneResource = 0;
        int oneCoin = 0;
        int countCoin[10];
        char answer = 'q';


        cout << "������� ����� ������ ���������:\t ";
        cin >> itemCount;
        cout << "������� ����� �������� ���������� ��� ������ ������:\t ";
        cin >> resorceCount;
        while(resorceCount > 5){
            cout << "������������ ����������!!!\n������� �� ����� 5: ";
            cin >> resorceCount;
        }

        cout << "�� ������ ��������� ��������� �� ������� ������� �������?(Y/N)" << endl;
        cin >> answer;
        while(answer != 'Y' && answer != 'N' && answer != 'y' && answer != 'n'){
            cout << "�������� ������" << endl;
            cin >> answer;
        }

        if(answer == 'y' || answer == 'Y'){
            for (int i=1; i <= resorceCount; i++){
            cout << "���� ������� " << i << " �������:\t ";
            cin >> countCoin[i];
            oneCoin += countCoin[i];
            }
        }

        for (int i=1; i <= resorceCount; i++){
            cout << "���������� " << i << " ������� �� ������� ����:\t ";
            cin >> count1[i];
            oneResource += count1[i];
        }

        cout << "\n��� " << itemCount << " ����� ��� ����������:\n";
        for (int i = 1; i <= resorceCount; i++){
            cout << count1[i] * itemCount << " ������ " << i << " �������\n";
            if(answer == 'y' || answer == 'Y'){
            cout << " � " << countCoin[i] * count1[i] * itemCount << " �������." << endl;
            }
        }

        return 0;
    }
    //������ ������� ������ ����� � ��������� ��������
    int itemsFunc(){
        int resorceTypesCount[5];
        int allResorceTypeCount[5];
        int resorceTypes = 0;
        int sum[10];
        int x=0;
        int y = 0;
        cout << "������� ����� �������� ����� ��� �������� 1 ����?\t";
        cin >> resorceTypes;
        cout << endl;
        while(resorceTypes > 5){
            cout << "������������ ����������!!!\n������� �� ����� 5: ";
            cin >> resorceTypes;
        }
        for (int i=1;i<=resorceTypes ;i++ ){
            cout << "������� ���������� �������� " << i << " ���� �� ���� ����?\t";// i1 = 12, i2 = 20;
            cin >> resorceTypesCount[i];
        }
        for (int i=1;i<=resorceTypes ;i++ ){
            cout << "\n������� � ��� �������� " << i << " ����?\t";
            cin >> allResorceTypeCount[i]; //i1 = 100 i2 = 200
        }
        for (int i=1;i<=resorceTypes ;i++ ){
                sum[i] = allResorceTypeCount[i] / resorceTypesCount[i];
                if(i==1)
                    x = sum[i];
                else
                    y=sum[i];
                if(i != resorceTypes)
                    cout << "�� " << allResorceTypeCount[i] << " �������� " << i << " ���� � \n";
                else{
                    if(x < y)
                        cout << "�� " << allResorceTypeCount[i] << " �������� " << i << " ���� ��������� " << x << " �����.";
                    else
                        cout << "�� " << allResorceTypeCount[i] << " �������� " << i << " ���� ��������� " << y << " �����.";
                }
        }
        return 0;
    }
};

class myMainClass //����� ��� ���� ����������
{
public:
    int whatAnswer = 0;
    int askFunc(){
        cout << "���������� ���������� �������� ��� �����? (1/2)\t";
        while(whatAnswer > 2 || whatAnswer < 1){
            cin >> whatAnswer;
            if(whatAnswer == 1){
                itemsCount items;
                items.resorceFunc();
            }else if (whatAnswer == 2){
                itemsCount items;
                items.itemsFunc();
            }else
                cout << "\n\n����� ������ ������ 1 ��� 2\n\n";
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
        cout << "\n\n��������� ����������?(Y/N)";
        cin >> no;
        if(no == 'N' || no == 'n')
            repeat = false;
        else if (no == 'y' || no == 'Y')
            repeat = true;
        else
            cout << "\n������� N ��� Y\n\n";
    }
    return 0;
}
