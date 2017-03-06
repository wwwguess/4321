// Room: /d/hhu/students.c

inherit ROOM;

void create()
{
	set("short", "ѧ����");
	set("long", @LONG
ѧ������װ�޵ĸ����ûʣ�
    һ¥��ѧ�������������ѧ���ڴ˴򷹡�
    ����һ�������и������������ѧ�������������(drink),
    ��Ķ��Ӳ����������˼������ǲ��ǸóԵ㶫���ˣ�
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
]));
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"hhu1road3",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/seller.c" : 1,
]));
	set("no_clean_up", 0);

	setup();
}
void init ()
{
        add_action("do_drink","drink");
}

int do_drink(string arg)
{
        if (!arg||arg=="")
           return notify_fail("��Ҫ��ʲô��\n");
        if (arg=="water")
           {
            return notify_fail("����ˮ��Ҫ�����ģ�����Ժȵ���(soup)\n");
           }

        if (arg!="soup")
           return notify_fail("�ܱ�Ǹ��ѧ���ǲ��ṩ"+arg+"\n");
        if ((int)this_player()->query("water") >= (int)this_player()->max_water_capacity())
        return notify_fail("����Ҳ�Ȳ���һ������\n");
       message_vision("$N������Ҩ��һ������������ȥ\n",this_player());
        this_player()->add("water",40);
        return 1;
}
