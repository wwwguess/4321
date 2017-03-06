inherit ROOM;

void create()
{
        set("short", "���Ⱦ�ͷ");
        set("long", @LONG
�����Ϊ�ͱڣ��⻬���һ�꺮������,���㸡����������Ƣ��ɽ����Ȼ�г�
һ��Ѩ(vase),������¶.
LONG
        );
        set("item_desc", ([
                "vase":
                    "ʯѨ��ƿ״,����������(interject)ʲô������.\n",
                          ]) );
        set("exits", ([ /* sizeof() == 1 */
                "east" : __DIR__"hollow1",
]));
        set("objects", ([ /* sizeof() == 1 */
                  __DIR__"obj/orchid" : 1,
]));
        set("no_magic", 1);

        setup();

}

void init()
{
        add_action("do_interject", "interject");
}
int do_interject(string arg)
{
        if( !arg || arg!="orchid" ) return notify_fail ("��Ҫ��ʲô��\n");
        message_vision("����������������,�ó���ɫ�⻪.$N�����Ʈ��...\n",
                this_player());
        tell_room("/d/latemoon/bamboo",this_player()->query("name") + "����Ʈ��.\n");
        this_player()->move("/d/latemoon/bamboo");
        return 1;
}
