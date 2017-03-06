// Room: /u/cloud/latemoon/hall.c

#include <room.h>

inherit ROOM;

string look_flower();

void create()
{
        set("short", "����ׯ");
        set("long", @LONG
����һ�����Ժ�������ò��Ů������������ѧϰ�Ÿ��պ��赸��
һλ���ɰ��Ů��������������Ȼ���衣��������ȵ����ˣ��㼸��
�����Գ֣�Ҳ��������С�
    Ժ������Щ���ݣ�һ�ɵ���������·�����ǽ����������ɫ�Ļ�
(flower)�������ġ�
    һ�ȹ���(door)ͨ��ׯ�⡣
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  		"east" : "u/cloud/latemoon/entrance",
]));

        set("item_desc", ([
                "door": (: look_door, "east" :),
		"flower": (: look_flower :),
        ]) );

        set("objects", ([
                CLASS_D("dancer") + "/master":1 ]) );

        create_door("east", "����", "west", DOOR_CLOSED);

        set("valid_startroom", 1);
        setup();
        "obj/board/dancer_b"->foo();
}

string look_flower()
{
	return "���ֻ���·��δ�������ط��������ྥ��Ҷ�ϻ���\n";
}

