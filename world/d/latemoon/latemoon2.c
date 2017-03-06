#include <room.h>

inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
�����������㿴��Ϯ��������̺���������ʮ���ŵ������ϣ���
��һɫ�����Ρ�С�죬���а���С���磬���ܹ���ɽˮī����һ��ľ
���ܣ��Ա߻���һ��ɴ��(closet)��
LONG
	);
	set("item_desc", ([
		"closet" : @TEXT
����һ���ϵ�ľ�����ɵ�С���ӣ��������һЩ��Ʒ��
�㿴��һ�������������Σ�����ȡ��(take cloth)������
TEXT
	]) );

	set("exits", ([ /* sizeof() == 2 */
		"west" :__DIR__"latemoon4",
	]));

    set("objects",([
        __DIR__"npc/zauron" :  1 ]) );
	create_door("west","����","east", DOOR_CLOSED);
	setup();
}

void init()
{
	add_action("do_take", "take");
	add_action("do_search","search");
}

void reset()
{
	::reset();
	set("take_available" , 2);
	set("make_cockroach", 5);
}

int do_take(string arg)
{
	object obj;

	if( !arg ) return notify_fail("��Ҫ��ʲô ? \n");
	if( arg !="cloth" ) { 
		if ( query("make_cockroach") ) {
			message_vision("$Nһ����� ! ͻȻ����һֻ����롣\n",this_player());
			obj = new(__DIR__"npc/cockroach");
			obj->move(environment(this_player()));
			add("make_cockroach", -1);
		}
		return 1;
	}
	if( query("take_available") ) {
		obj = new(__DIR__"obj/skirt");
		obj->move(this_player());
		message_vision("$N�ӳ�����ȡ��$n��\n",this_player(),obj);
		add("take_available", -1);
		return 1;
	}
	write("�����ڵ��·������ù��ˡ�\n");
	return 1;
}

int do_search(string arg)
{
	object obj,who;

	who = this_player();
	if ( !arg )	return notify_fail("��Ҫ��ʲô?\n");
	if ( arg !="bracelet" )	{
		 write("��äĿ�����������޷���ʲô!\n");
	  return 1;
	}
	else  {
	if( !who->query_temp("moon/�����") ) {
	 write("��äĿ�����������޷���ʲô!\n");
		return 1;
	}
	 if ( who->query_temp("latemoon/����") ) {
		 write("�㷭�䵹�����ҳ��������ƺ���������\n");
		 return 1;
	 }
     obj = new("/d/latemoon/obj/bracelet");
	 obj->move(who);
	 message_vision("$N�ӳ�����ȡ��$n��\n",this_player(),obj);
	 who->set_temp("latemoon/����", 1);
	return 1;
	}
}
