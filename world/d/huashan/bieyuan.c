// bieyuan.c

inherit ROOM;

void create()
{
        set("short", "��ɽ��Ժ");
        set("long", @LONG
������ǻ�ɽ��Ժ���ڡ���ɽ�������������󣬽���һ��Ϳ�أ��ó�
����֮λ���ڴ˿�����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
		"southdown" : __DIR__"laojun",
]));

        set("objects", ([
                CLASS_D("huashan") + "/fengbuping" : 1,
                CLASS_D("huashan") + "/chengbuyou" : 1]));
        setup();

        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}

