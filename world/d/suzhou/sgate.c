//ROOM: d/suzhou/sgate.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;   

string look_gaoshi();

void create()
{
	set("short", MAG"�ϳ���"NOR);
	set("long", @LONG
	  ��������������֮�Ƶ����ݵ��ϳ��ţ��������Ϸ�д�С����š��������֣�
��ǽ������һ�Ÿ�ʾ(gaoshi)���ٱ��ǽ䱸ɭ�ϡ�һ����ֱ����ʯ�����򱱱ߡ���
���ǽ��⣬����ͨ���ݡ������ǳ��
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"south" : __DIR__"hye",
		"up" : __DIR__"sclou", 
		"north" : __DIR__"sroad2",
]));  
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
]));
	set("objects", ([
		__DIR__"npc/bing" : 3,
		 "/obj/npc/wujiang1"+random(3) : 1,
]));
	setup();
}   
    
string look_gaoshi()
{
        return "Ϊ���ȫ�������������裬���Ҳ�Ҫ�Ҷ�������\\n\n\t\t����֪��\n\n\t\t    �\n";
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







