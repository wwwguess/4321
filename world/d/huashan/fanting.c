// Room: /d/shaolin/fanting.c
// Date: YZC 96/01/19
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
�����ǻ�ɽ���ӾͲ͵ĵط����������󣬷��˼������Ρ�
������ɽ�������ڲ��ˡ�
LONG
        );
        set("exits", ([
                "north" : __DIR__"houhuayuan1",
        ]));
        set("objects",([
                "/d/shaolin/obj/qingshui-hulu" : 1,
                names[random(sizeof(names))]: 1,
                names[random(sizeof(names))]: 1,
        ]));
        setup();
        replace_program(ROOM);
}
