// Room: /u/cloud/entrance.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "�����");
        set("long", @LONG
���������������.
    ���������������ˮ������һ������, ������ҵ�����ʢ����Ҷ��
Ϊ���������������������߹��������ھ��������ķ�ɽ���ɱ������ڵ�
ѩͤ��; �����и��ɿ�, ���˽��������ֵ�֧�� -- ɽ���¡�
    ���Ϻ�������, ��������������ϱ߼����ϴ����Ľ�������
    ��ڴ��и��ٸ��Ĺ���(sign), ��֪��д��Щʲô�� 
LONG
        );

        set("item_desc", ([
                "sign": (: look_sign :)
        ]) );

        set("exits", ([ /* sizeof() == 2 */
		  "northwest" : __DIR__"dragonhill/sroad",
		  "south" : "/u/cloud/nwroad1",
	]));

 //       set("outdoors", "cloud");

        setup();
//        replace_program(ROOM);
}

string look_sign(object me)
{
        return "������д��:[����] �ɴ�������ȡ�ƽ�һ��\n";
}

