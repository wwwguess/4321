//by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"��Ժ"NOR);
	set("long", @LONG
	  ��������Ժ�ӱ�ǰ��СЩ��Ժ�����������ӡ�ÿ�������°׵���ҹ��
���˾ͻ�����������Ǻ��˰�������������������ֽС�����СԺ����������
һ�ŷ��ӣ��ͽС����������������˷�������������ʱ��ȴ��Ϊ����������������
����Ϊ�����񡿱������ţ�����ȴ���ס�
LONG
	);
	set("exits", ([
		"west" : __DIR__"lou.c",
		"south" : __DIR__"ting.c",
]));
	setup();
}

void init()
{
	add_action("do_yell", "yell");
}

int do_yell()
{       
	object ob,me;
	me=this_player();

        if( !me->query("mark/����")) return 0;
	
	ob = new(__DIR__"npc/mrfeng");
	ob->move(__DIR__"guarden2");
	tell_room(__DIR__"guarden2", RED"ֻ�����˷����������������������˳�����\n\n"NOR);
	if ( me->query("mark/����") )
        me->delete("mark/����");         
    		return 1;  
}
