//ROOM: d/suzhou/wgate.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;  

string look_gaoshi();

void create()
{
	set("short", MAG"������"NOR);
	set("long", @LONG
	  ��������������֮�Ƶ����ݵ������ţ��������Կ���ɭ�ֵı�Ե������
���Ϸ�д�С����š��������֣���ǽ������һ�Ÿ�ʾ(gaoshi)���ٱ��ǽ䱸ɭ�ϡ�
һ����ֱ����ʯ���������������졣·�Ͽ��Կ���ȥ���Ե��ˡ������ǳ��
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"west" : __DIR__"szroad6",
		"up" : __DIR__"wclou",      
		"east" : __DIR__"wroad4",
]));  
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
]));
	set("objects", ([
		__DIR__"npc/bing" : 3,
	//	"/d/city/npc/wujiang1"+random(3) : 1,
]));
	setup();
}    

string look_gaoshi()
{
        return   "Ϊ���ȫ�������������裬���Ҳ�Ҫ�Ҷ�������\n\n\t\t����֪��\n\n\t\t    ��\n";
}

void init()
{
        object me,guanchai;

        me = this_player();

        if( interactive(me) && me->query("pk_exp") > 0 && !me->query_temp("be_ki
lled"))
        {
        message_vision(HIR "ͻȻ��б������һ���ٲ\n\n" NOR, this_player());
        guanchai=new("/d/city/npc/guanchai");
        guanchai->move("/d/city/dongmen");
        write(RED"�ٲ��ȵ�����������С����������\n"NOR);
        }


}

int valid_leave(object me, string dir)
{

        if( me->query("pk_exp") > 0 )
        {
                return notify_fail("�㻹û�жԸ��ٲ��ô�뿪���\n");
        }
        return ::valid_leave(me, dir);
}






