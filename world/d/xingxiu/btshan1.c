// room: /d/xingxiu/btshan
// Jay 3/27/96

inherit ROOM;

void create()
{
        set("short", "����ɽׯ");
        set("long", @LONG
�����ǡ�������ŷ���������ĵط�������ʲô����Ҳû�С�
LONG
        );
        set("exits", ([ 
            "eastdown" : __DIR__"btshan",
        ]));
        set("objects", ([ 
		"/kungfu/class/btshan/ouyang-feng" : 1,
		"/kungfu/class/btshan/snake" : 5,
         ]) );

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}
