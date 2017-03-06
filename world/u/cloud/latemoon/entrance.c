// Room: /u/cloud/latemoon/entrance.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "��ʯС��");
	set("long", @LONG
�������ö���ʯ�̳ɵ�С·���������Կ���һ���õ���ɫΧǽΧס
��ͥԺ�����������Ų��µ�Ů��Цӯӯ��վ������˵Ц�ţ���������
һ�ȹ���(door)���ܶ�����д��"����ׯ"��Ժǽ�Ǳ�Ʈ��������������
�˻��ǣ���Լ�����ŵ�һ��������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
//  "west" : "/u/cloud/latemoon/hall",
  "west" : "/d/latemoon/gate",
  "east" : "/u/cloud/wroad1",
]));
	set("outdoors", "cloud");

        set("item_desc", ([
                "door": (: look_door, "west" :),
        ]) );

	set("objects", ([
		"/u/cloud/npc/lm_guard": 2 ]) );

	create_door("west", "����", "east", DOOR_CLOSED);

	setup();
	replace_program(ROOM);
}

/*
void init()
{
	exist_door(ob);
}

void exist_door(object ob)
{
        if( (string)ob->query("gender") == "Ů��"  )
	        create_door("west", "����", "east", DOOR_CLOSED);
}
*/
