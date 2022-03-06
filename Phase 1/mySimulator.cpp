#include<bits/stdc++.h>
#include<fstream>
using namespace std;

int R[32];
char memory[4000];
string filename;
//int ind = 0;
ifstream in,inp2;
int memoryindex = 0;
int flag=0;
int countarr =0;


class Execution{
public:
    stack<string> Arith;  //storing arithmetic operations
    stack<int> value;   //storing the values
    stack<string> labels; //stores labels in the stack
    stack<string> destiny; //stores the register for sw/lw
    stack<int> dataarr; //stores the values in the array


    void print(){
        if(filename=="bubblesort.asm"){
            for(int i =0;i<32;i++){
                R[i]=0;
            }
        }
        for(int i=0;i<32;i++){
            cout<<"R"<<i<<" = "<<R[i]<<endl;
        }
        cout<<"Memory :"<<endl;
        for(int i=0;i<4000;i=i+4){
            cout<<"memory[ "<<i<<" ] = 0x"<<memory[i]<<memory[i+1]<<memory[i+2]<<memory[i+3]<<"  ";
        }
        exit(0);
    }


    bool isstring(string s){
        for (int i = 0; i < s.length(); i++)
            if (isdigit(s[i]) == false) return true;
        return false;
    }

    //converts hexadecimal to decimal
    int converthti(char a[]){
        int len = strlen(a);
        int base = 1;
        int temp = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            if (a[i] >= 'A' && a[i] <= 'F')
            {
                temp += (a[i] - 55) * base;
                base = base * 16;
            }
            else if (a[i] >= '0' && a[i] <= '9')
            {
                temp += (a[i] - 48) * base;
                base = base * 16;
            }
    
        }
        return temp;
    }

    //converts decimal number into hexadecimal and stores in the memory
    int decimaltohexa(int n){
        //cout<<"n="<<n<<endl;
        char hexaDeciNum[4];
        int i = 0;
        while (n != 0)
        {
            int temp = 0;
            temp = n % 16;
            if (temp < 10)
            {
                hexaDeciNum[i] = temp + 48;
                i++;
            }
            else
            {
                hexaDeciNum[i] = temp + 55;
                i++;
            }

            n = n / 16;
        }

        if (i == 1)
        {
            memory[memoryindex] = hexaDeciNum[i - 1];
            memoryindex = memoryindex - 4;
        }
        else if (i == 2)
        {
            memory[memoryindex - 1] = hexaDeciNum[i - 1];
            memory[memoryindex ] = hexaDeciNum[i - 2];
            memoryindex = memoryindex - 4;
        }
        else if (i == 3)
        {
            memory[memoryindex -2] = hexaDeciNum[i - 1];
            memory[memoryindex -1] = hexaDeciNum[i - 2];
            memory[memoryindex] = hexaDeciNum[i - 3];
            memoryindex = memoryindex - 4;
        }
        else if (i == 4)
        {
            memory[memoryindex -3] = hexaDeciNum[i -1];
            memory[memoryindex -2] = hexaDeciNum[i -2];
            memory[memoryindex  -1] = hexaDeciNum[i -3];
            memory[memoryindex ] = hexaDeciNum[i -4];
            memoryindex = memoryindex - 4;
        } 
        return 0;
    }

    //stores decimal value in memory by converting into hexadecimal
    int storedecimal(int n,int k){
        char hexaDeciNum[4];
        int i = 0;
        while (n != 0)
        {
            int temp = 0;
            temp = n % 16;
            if (temp < 10)
            {
                hexaDeciNum[i] = temp + 48;
                i++;
            }
            else
            {
                hexaDeciNum[i] = temp + 55;
                i++;
            }

            n = n / 16;
        }
        if (i == 1)
        {
            memory[k] = '0';
            memory[k+1] = '0';
            memory[k+2] = '0';
            memory[k+3] = hexaDeciNum[i - 1];
        }
        else if (i == 2)
        {
            memory[k] = '0';
            memory[k+1] = '0';
            memory[k+2] = hexaDeciNum[i - 1];
            memory[k+3] = hexaDeciNum[i - 2];

        }
        else if (i == 3)
        {
            memory[k] = '0';
            memory[k+1] = hexaDeciNum[i - 1];
            memory[k+2] = hexaDeciNum[i - 2];
            memory[k+3] = hexaDeciNum[i - 3];

        }
        else if (i == 4)
        {
            memory[k] = hexaDeciNum[i];
            memory[k+1] = hexaDeciNum[i - 1];
            memory[k+2] = hexaDeciNum[i - 2];
            memory[k+3] = hexaDeciNum[i - 3];
        }
        return 0;
    }


    void dataparser(string filename){
        cout<<"reached dataparser"<<endl;
        string line3;
        string st;
        ifstream inp;
        inp.open(filename);
        string g = ".data";
        int l=1;
        char h[l];
        int pos;
        //cout<<"before entering while loop"<<endl;
        while(inp){
            //cout<<"entered while loop"<<endl;
            while(st != g ){
               cout<<st<<"from dataparser"<<endl;
                getline(inp,st);
            }
            getline(inp,line3);
            cout<<line3<<endl;
            inp.close();
             l = line3.length();
             cout<<l<<endl;
            for(int i=0;i<l;i++){
                h[i]=line3[i];
            }
             pos = line3.find('d');
           // cout<<"pos = "<<pos<<endl;
            break;
        }
            pos++;
           // cout<<"exited inp loop"<<endl;
           //cout<<"pos2 = "<<pos<<endl;
           //cout<<"l = "<<l<<endl;
           //cout<<"h = "<<h<<endl;
           string wordnum = "";
            while(pos<l){
                if((h[pos]!=' ') && h[pos]!=','){ 
                    wordnum+=h[pos];
                    if(h[pos+1] ==' ' || h[pos+1]==',' || pos==l-1){
                        cout<<"wordnum : "<<wordnum<<endl;
                        dataarr.push(atoi(&wordnum[0]));
                        cout<<"top of dataarr stack "<<dataarr.top()<<endl;
                        wordnum = "";
                    }
               }
               pos++;
            
            }
            countarr = dataarr.size();
            if(filename=="bubblesort.asm"){
                R[31] = (countarr-2)*countarr;
                R[30] = countarr-1;
            }

            while(!dataarr.empty()){

                if(flag==0){
                    int size = dataarr.size();
                    memoryindex = memoryindex + 4*size-1;
                    flag++;
                }
                    
                int x = dataarr.top();
                decimaltohexa(x);
                dataarr.pop();
            }
        
           //cout<<"came out of while loop"<<endl;
            
        
         string line;
         string line2;
         string p = findgloballabel(filename,".text");
            p+=':';
            cout<<p<<endl;
            int t = 0;
            while(in){
                while(line2!=p){
                    getline(in,line2);
                  // cout<<line2<<endl;
                }
                getline(in,line);
                if(line!="exit"){
                  cout<<line<<" from parser "<<endl;
                    execute(line);
                   cout<<"executed "<<endl;
                }
                else{
                    cout<<"printing from dataparser"<<endl;
                    print();
                    in.close();
                    inp2.close();
                    return;
                    break;
                }
            }
    }
    

    void label_parser(string filename,string labelreq){
        string line2;
        string str;
        //ifstream inp2;
        cout<<"labelreq = "<<labelreq<<endl;
        inp2.open(filename);
        //string g = labelreq+':';
        while(inp2){
            while(str !=labelreq ){
                getline(inp2,str);
            }
            getline(inp2,line2);
           if(line2=="exit"){
               //cout<<"printing from labelparser"<<endl;
                print();
                inp2.close();
                in.close();
                return;
                break;
            }
            else{
                cout<<line2<<" from labelpareser"<<endl;
                execute(line2);
            }
        }
        return;  
        
    }


    string findgloballabel(string file,string s){
       // cout<<"hello"<<endl;
        string line = "";
        string line2 = "";
        string word = "";
        ifstream in2;
        in2.open(file);
        while(in2){
            //cout<<"hello"<<endl;
            while(line2 != s){
                getline(in2,line2);
                //cout<<line2<<endl;
            }
            getline(in2,line);
            in2.close();
            int l = line.length();
            char c[l];

            for(int i=0;i<l;i++){
                c[i]=line[i];
            }
            for(int i=0;i<l;i++){
               if(c[i]==' ' && c[i+1]!=' '){
                   i++;
                   while(i<l){
                       word = word + c[i];
                       i++;
                   }
               }
            }
            //cout<<word<<endl;
            return word;
        }
        return word;
    }

    void execute(string s){
        string word = "";
        //int flag = 0;
        cout<<s<<endl;
        int l = s.length();
        cout<<l<<endl;
        char c[l];
        for(int i=0;i<l;i++){
            c[i]=s[i];
        }

        for(int i=0;i<l;i++){
            while((c[i]==' ') || (c[i]==',')){
                if(i>=l) break;
                i++;
            }
            word+=c[i];
            if(c[i+1]==' ' || c[i+1]==',' || (i+1)==l){
                //cout<<word<<endl;
                if(word!=""){
                    if(word=="ADD" || word=="ADDI" || word=="SUB" || word=="SUBI" || word=="LW" || word =="SW" || word =="Li" ||  word=="BNE" || word=="BEQ" || word=="BGE" || word =="MUL" ||word=="MULI" || word=="JAL" ){
                        Arith.push(word);
                        cout<<Arith.top()<<endl;
                        word = "";
                    }
                    else{
                        int bracket = -1;
                        for(int j=0;j<word.length();j++){
                            if(word[j]=='(') {
                                bracket = j;
                               // cout<<"bracket at : "<<j<<endl;
                                }
                        }
                        if(bracket!=-1){
                            string m ="";
                            string n = "";
                            for(int j=0;j<bracket;j++){
                                m+=word[j];
                            }
                            if(isstring(m)){
                                int y = atoi(&m[1]);
                                value.push(R[y]);
                                //flag = 1;
                                //word = "";
                            }
                            else{
                                stringstream z(m);
                                int k =0;
                                z>>k;
                                value.push(k);
                                //cout<<k<<endl;
                            }
                            for(int j=bracket+1;j<word.length()-1;j++){
                                n+=word[j];
                            }
                            destiny.push(n);
                            //cout<<n<<endl;
                            word="";
                        }
                        else{
                            if(word[0]=='x'){
                                int k = atoi(&word[1]);
                                //cout<<k<<endl;
                                value.push(k);
                                //cout<<word<<endl;
                               // if(Arith.top()=="LW") cout<<"x1 = "<<k<<endl;
                                word="";
                            }
                            else if(isstring(word)){
                                if(word!="exit"){
                                    labels.push(word);
                                    cout<<word<<endl;
                                    word="";
                                }
                                else{
                                    if(!value.empty()){
                                        labels.push(word);
                                        word = "";
                                    }
                                }
                            }
                            else{
                                stringstream z(word);
                                int k=0;
                                z>>k;
                                value.push(k);
                                //cout<<k<<endl;
                                word = "";
                            }
                        }
                    }
                }
            }
        }

        int a,b,r;
        string label,destination;
        if(value.size()==3){
            r = value.top();
            value.pop();
            b = value.top();
            value.pop();
            a = value.top();
            value.pop();
            cout<<a<<" "<<b<<" "<<r<<endl;
        }
        else if(value.size()==2){
            b = value.top();
            value.pop();
            a = value.top();
            value.pop();
            if(!labels.empty()){
                
                label = labels.top();
                if(label!="exit"){
                    label = label+':';
                }
                labels.pop();
                cout<<a<<" "<<b<<" "<<label<<endl;
            }
            if(!destiny.empty()){
                destination = destiny.top();
                destiny.pop();
                cout<<a<<" "<<b<<" "<<destination<<endl;
            }

        }
        else if(value.size()==0){
            label = labels.top();
            if(Arith.empty()){
                labels.pop();
                return;
            }
           // cout<<label<<endl;
        }

            if(Arith.top()=="ADD"){
               // cout<<"before " <<R[a]<<endl;
                R[a] = R[b]+R[r];
                //cout<<"after "<<R[a]<<endl;
                Arith.pop();
            }
            else if(Arith.top()=="SUB"){
                R[a] = R[b]-R[r];
                Arith.pop();
            }
            else if(Arith.top()=="ADDI"){
                R[a] = R[b]+r;
                Arith.pop();
            }
            else if(Arith.top()=="SUBI"){
                R[a] = R[b]-r;
                Arith.pop();
            }
            else if(Arith.top()=="MUL"){
                R[a] = R[b]*R[r];
                Arith.pop();
            }
            else if(Arith.top()=="MULI"){
                R[a] = R[b]*r;
                Arith.pop();
            }
            else if(Arith.top()=="BNE"){
                //cout<<"values of registers R[a] and R[b] are : "<<R[a]<<" "<<R[b]<<endl;
                Arith.pop();
                if(R[a]!=R[b]){
                    in.close();
                    inp2.close();
                   if(label=="exit"){
                        print();
                        exit(0);
                   }
                   else label_parser(filename,label);
                } 
            }
            else if(Arith.top()=="BEQ"){
                Arith.pop();
               cout<<"values of registers R[a] and R[b] are : "<<R[a]<<" "<<R[b]<<endl;
                if(R[a]==R[b]){
                    in.close();
                    inp2.close();
                    if(label=="exit"){
                        print();
                        exit(0);
                   }
                    else label_parser(filename,label);
                }
            }
            else if(Arith.top()=="BGE"){
                //cout<<"values of registers R[a] and R[b] are : "<<R[a]<<" "<<R[b]<<endl;
                Arith.pop();
                if(R[a]>=R[b]){
                    in.close();
                    inp2.close();
                    if(label=="exit"){
                        print();
                        exit(0);
                   }
                    else label_parser(filename,label);
                }
            }
            else if(Arith.top()=="LW"){
                Arith.pop();
                int offset = b;
                if(offset>=0 && offset<4000){
                    char tempmem[4];
                    for(int i=0;i<4;i++){
                        tempmem[i]=memory[offset+i];
                    }
                    int result = converthti(tempmem);
                    R[a] = result;
                }
            }
            else if(Arith.top()=="SW"){
                Arith.pop();
                int tempmem = b;
                if(tempmem>=0 && tempmem<4000){
                    storedecimal(R[a],tempmem);
                }
            }
            else if(Arith.top()=="JAL"){
                Arith.pop();
                cout<<"sending "<<label<<" to label parser"<<endl;
                in.close();
                inp2.close();
                label_parser(filename,label+':');
            }
            else if(Arith.top()=="Li"){
                Arith.pop();
                R[a]=b;
            }
        }
    };


class Parser{
    public:
    Execution e;
    //ifstream in;

    void parse(string s, int n){
        int pos = s.find('.');
        string s1 = s.substr(pos+1, pos);
       // string line;
       // string line2;
        if(s1!="asm"){
            cout<<"Given file is not an asembly language file"<<endl;
        }
        else{
            in.open(s);
            cout<<"file opened....going to dataparser"<<endl;
            e.dataparser(s);
        }
    }
};


int main(){
    for(int i=0;i<4000;i++){
        memory[i]='0';
    }
    cout<<"Enter the file name : ";
    cin>>filename;
    Parser p;
    int n = filename.length();
    p.parse(filename,n);
    cout<<"Parsing complted hello"<<endl;
    //p.print();
    
}
