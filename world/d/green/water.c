#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short","Ϫˮ��");
	set("long",@LONG
��������һ��СϪ���Աߣ�Ϫˮ���峺��������������ȥ������
��ľ��������������С·��
��Ȼˮ(water)����һ������������������������ʲô�����Ƿ�Ҫ��ȥ
��һ��(search)?
LONG
);
	set("exits",([
	"west" :__DIR__"outdoor",
	"north":__DIR__"stoneroom",
	]) );
	create_door("north","����","south",DOOR_CLOSED);
	setup();
}

void init()
{
	add_action("do_search","search");
}

int do_search(string arg)
{
	object me,obj;
	
	me = this_player();
	if ( !arg || arg != "water" )
		return notify_fail("��Ҫ���Ƕ���?\n");

        message_vision("$N����Ϫˮ֮�У���ʼ��ϸѰ��....\n",me);		

	if ( me->query("������") ) {
	   if ( random(2) ) {
		obj = new("/d/green/obj/windsword");
		obj->move(me);
		message_vision("$N����ˮ���ҳ�һ��"+HIW"׷�罣"NOR+"!\n", me);
		return 1 ;
	   }
	   me->delete("������");
	}
        message_vision("$N��ˮ��æ�˰��죬���һ������\n",me);		
	return 1 ;
}

