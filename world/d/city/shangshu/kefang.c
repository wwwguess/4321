// /d/city/shangshu/kefang

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "�ͷ�");
        set("long",@LONG
���߽������鸮�Ŀͷ����ͷ����󣬵����õñȽ����ࡣ������
С���������ż�����(book)����һ���ǽ������˰ѱ������ƺ�����
���˴˵����˾�������˫ȫ��
LONG
        );

        set("exits", ([
		"west":		__DIR__"road2"
                ]));

	set("item_desc", ([
		"book":	(: "һ��ʫ�ʼ�������ȦȦ�����һЩ����.\n" :),
		]) );

	create_door ("west", "ľ��", "east", DOOR_CLOSED);

        setup();
}

