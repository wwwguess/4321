// ban.c
// Created by sbaa
#define BANNED_SITES "/data/notcon"
string *Sites;

void create()
{
	seteuid(getuid());
}
void remove(string site)
{     int i,j;
	for (i = 0; i < sizeof(Sites); i++)
		if (Sites[i]==site) { rm (BANNED_SITES);
                    Sites[i]="";
  for (j=0;j<sizeof(Sites);j++) write_file(BANNED_SITES, Sites[j] + "\n", 0);  
	write( site+ "���ѽ����\n");return; }
            write("û�з�"+site+"\n");
 
}

void add(string site)
{
	int i;
	for (i = 0; i < sizeof(Sites); i++)
		if (Sites[i]==site) { write( site+ "�ѱ������\n");return;}

	Sites += ({site});
	write_file(BANNED_SITES, Sites[sizeof(Sites)-1] + "\n", 0);
      write( site+ "���ѱ��⡣\n");

}
void print()
{
	int i;
	for (i = 0; i < sizeof(Sites); i++)
		write(Sites[i] + "\n");
}



void load_sites()
{
	string *tmp, file;
	int loop;

	Sites = ({});
	
	// reads in the list of the banned sites

	file = read_file(BANNED_SITES);
	if (!file) return;
	
	tmp = explode(file, "\n");
   	for(loop=0; loop<sizeof(tmp); loop++)
        	if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
           		continue;
        	else Sites += ({ tmp[loop] });
}


int main(object me, string arg)
{
	string site;
           	load_sites();
	if (!arg)
		print();
	else if (sscanf(arg, "+ %s", site) == 1) {
	
			add(site);
		}
	else if (sscanf(arg, "- %s", site) == 1)
		remove(site);
	else write("ָ���ʽ��ban [+|- site]\n");


	return 1;
	
}

int help(object me)
{
	write(@HELP
ָ���ʽ��ban [+|- site]

����������������ֹ�������⵷�ҡ�
HELP
	);
	return 1;
}
