#include <ansi.h>
#include <weapon.h>

inherit HAMMER; 

void create()
{
        set_name(  "����" , ({ "case" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",

"����һ������ͨͨ�����ӡ����������make����remake��������\n"
);
                set("value", 1);
                set("material", "wood");
                set("rigidity", 100000);
                set("weapon_prop/agility", 0); 
                set("weapon_prop/personality", 0);
        }

        init_hammer(120);
        setup();

}
 
void init()
{
	add_action("do_make","make");
}

int do_make(string arg)
{
	object me;
	object obj;
	me=this_player();
	if(!arg) return 0;
	{
		if(arg=="axe")        {obj=new(__DIR__"cmaxe");obj->move(me);
write("�㽫���е����Ӵ򿪣������е����ƴ����һ�Ѹ���\n");}
        	if(arg=="blade")      {obj=new(__DIR__"cmblade");obj->move(me);
write("�㽫���е����Ӵ򿪣������е����ƴ����һ�ѵ���\n");}     	
		if(arg=="dagger")     {obj=new(__DIR__"cmdagger");obj->move(me);
write("�㽫���е����Ӵ򿪣������е����ƴ����һ��ذ�ס�\n");}
        	if(arg=="fork")       {obj=new(__DIR__"cmfork");obj->move(me);
write("�㽫���е����Ӵ򿪣������е����ƴ����һ�Ѳ档\n");}
        	if(arg=="hammer")     {obj=new(__DIR__"cmhammer");obj->move(me);
write("�㽫���е����Ӵ򿪣������е����ƴ����һ�Ѵ���\n");}
        	if(arg=="staff")      {obj=new(__DIR__"cmstaff");obj->move(me);
write("�㽫���е����Ӵ򿪣������е����ƴ����һ���ȡ�\n");}   
	     	if(arg=="sword")      {obj=new(__DIR__"cmsword");obj->move(me);  
write("�㽫���е����Ӵ򿪣������е����ƴ����һ�ѽ���\n");}
        	if(arg=="whip")       {obj=new(__DIR__"cmwhip");obj->move(me);
write("�㽫���е����Ӵ򿪣������е����ƴ����һ�ѱޡ�\n");}		
		destruct(this_object());
		
	}
	return 1;
}          
  