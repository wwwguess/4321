// Room: /d/city/street15.c
inherit ROOM;
void create()
{
        set("short", "��ʦ�ֵ�");
        set("long", @LONG
��������ʦ�Ĵ�֡������ǻ����µĴ��ţ������������ơ�
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
//             "north" :    __DIR__"templegate",
             "west"  :    __DIR__"street14",
             "east"  :    __DIR__"street7",]));
/*        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );*/

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

