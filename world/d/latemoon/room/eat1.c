
inherit ROOM;

void create()
{
    set("short", "����");
	set("long", @LONG
���߽�һ��װ�λ����Ĵ�������һ��˵���������ɣ�һ��ɼľ  
���εĴ�Բ�������������룬����˿��������ϵ��Ϻ������̣���
��Ĵ����룬���׽�ꡣʮ���ݻ�����������ׯ������͵ĵط���ƽ
��Ҳ��ׯ����ׯ�ڱ��ݸߵ�ǰ�����ŵĵط���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "east" :__DIR__"eat2",
     "west" :__DIR__"twoc",

]));

    set("objects", ([
        "/d/latemoon/obj/food2" : 1,
        "/d/latemoon/obj/food3" : 2,
    ]));
	setup();
	replace_program(ROOM);
}
