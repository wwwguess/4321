inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
������ǰ�ɽ������ɽ�����ıڿ���һ���Ϊ����......
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "down" : __DIR__"guyehill",
                   ]));
        set("objects", ([
                __DIR__"obj/goldenrope" : 1,
               ]) );

        setup();
        replace_program(ROOM);
}

