#include <room.h>  
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short",HIR "����" NOR);
  set("long",@LONG
���򣬺��̺���촰�������ﴦ���Ǻ�ɫ�ģ�����Ŀɰ����������ۡ�ǽ�Ͽ���
һ��ʫ:
                  ���м��˹����ϣ�һ�轣�����ķ���
                  ������ɽɫ��ɥ�����Ϊ֮�õͰ���
                  ������������䣬����Ⱥ�������裬
                  ������������ŭ�����罭������⡣
LONG
  );
  	set("exits/center" ,__DIR__"shishi");
    set("objects", ([
                __DIR__"npc/redgirl" : 1,
       ]) );
  
  setup();
 }
void init()
{
	add_action("do_prac","practice");
}
void reset()
{
    ::reset();
 	delete_temp("mark/gived");
}  
int do_prac(string arg)
{
	object me;
	object ob;
	object sword;
	me=this_player();
	if (!(ob=present("red girl",this_object()))) return 0;   
	if (!("/cmds/std/practice")->main(me,arg)) return 1;
    if (!arg) return 1;
    if (query_temp("mark/gived")) return 1;
    if (!random(20))
    { 
    	set_temp("mark/gived",1);
        tell_object(me,ob->name()+"�ó�ݵ�Ŀ�⿴���㣺����...���̫���ˡ�\n");
        tell_object(me,ob->name()+"����������һ������...\n");
        sword=new(__DIR__"obj/csword");
        sword->move(me);
    }
      
    return 1;
}	