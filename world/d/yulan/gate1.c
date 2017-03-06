// Room: /d/maintown/mt_gate1.c

#include <room.h>

inherit ROOM;

string look_bugao(object me);

void create()
{
	set("short", "���ſ�");
	set("long", @LONG
�����ǰ���Ǵ��е�Ŀ�ĵأ�������ɳ�ǣ����һ��ʱ�䣬�����˳�͢�ͽ�
����ʿע��ĵط�������Ŵ����ש���ĳ�ǽ����Ȼ�Ѿ����ϰ������ʷ��ȴ
��Ȼ�ǳ���̣���¥�������پ��Ĵ��֡���ɳ��ֱ���Ʊڷ�ȥ�����ſڵĸ�
���������������ľ��������װ��ǰ�촦���Ľ���������ͷ(head)��
�򱱾����Ǻ�ʵ�Ĵ���(gate)���Ϸ���һ��������е�С·ͨ��Զ����
LONG           
);

	set("item_desc", ([
		"gate":"����һ�º������ߵĴ�ľ�ţ����ú���ˢ�¹�������ȥ
����һ�ɹ�ζ��\n",

		"head":"�����뷢��ɢ����ͷ����Ŀ��Ȼ�ѿ�ʼ���ã������ܿ�
���ǹɿ־�ͷ�ŭ�ı���\n",


	]) );

	set("exits", ([ /* sizeof() == 2 */
		  "west" : "/d/yulan/gate2",
		  "east" : "/d/yulan/road",]));


	set("objects", ([
		"/d/maintown/npc/gateman" : 2 ]) );  

        set("no_clean_up", 0);
        set("outdoors", "maintown");

        create_door("west", "��ɳ�Ǵ���", "east", DOOR_CLOSED);
        
	setup();
        replace_program(ROOM);
}

