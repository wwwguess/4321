// Room: fanting.c
// Date: by yuer
inherit ROOM;
string* names = ({
        "/d/shaolin/obj/mala-doufu",
        "/d/shaolin/obj/bocai-fentiao",
        "/d/shaolin/obj/shanhu-baicai",
        "/d/shaolin/obj/liuli-qiezi",
});
void create()
{
        set("short", "����");
        set("long", @LONG
���������̵��ӾͲ͵ĵط����������󣬷��˼������Ρ�
�������̵������ڲ��ˡ�
LONG
        );
        set("exits", ([
                "east" : __DIR__"zoulang1",
        ]));
        set("objects",([
                "/d/shaolin/obj/qingshui-hulu" : 1,
                names[random(sizeof(names))]: 1,
                names[random(sizeof(names))]: 1,
        ]));
        setup();
        replace_program(ROOM);
}

