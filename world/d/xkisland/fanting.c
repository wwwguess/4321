//xk island.�����.c
//dan
#include <ansi.h>

inherit ROOM;

void create()
{


 set("short", "�����");
    set("long", @LONG
ǧ��Ŷ�,�Ĵ������������.�ı��Ѿ��߲߰���,��ϡ�ɼ���
Щ�Ѻ���.ǽ���������Ͳʻ���һЩ�ֻ�. ��һЩ���ֺ�����
�ڱ����۱߳Ե��ġ��������Զ����������yao����.
LONG
    );
    set("exits", ([ /* sizeof() == 2 */
      
      "east" : __DIR__"cave", 
      
    ]));
    set("objects",([
		__DIR__"npc/lisi" : 1, 
                
	]));
	set("no_fight", 1);
	set("no_sleep", 1);
	setup();
   
    
}    
void init()
{
        add_action("do_yao", "yao");

}

int do_yao()
{
	this_player()->start_busy(5);
	write(YEL "���Ӹ���һЩ���ĺͲ�ˮ.\n" NOR);
	write(YEL "��Ա����㣬�����죬����������ˡ�\n" NOR);	
	this_player()->set("food",350);
	this_player()->set("water",350);
	return 1;
}
