// Mon  08-21-95

inherit ROOM;

string long_desc();

void create()
{
    set("short", "�ݺ�յ�");
    set("long", (: long_desc :) );
    set("long.desc", @LONG
�������ݺ�һ���յ�, ���泤�����Ӳ�. �����Ǵ�ֱ��ɽ��, ���Ͽ�
�ƺ����Կ���һ��ͻ��������ʯ. �ұ��Ͽɿ������ٿӶ� (hole).
LONG
	);
    set("item_desc", ([
    "hole" : @HOLE
��ϸ�ع۲���Щ�Ӷ���, �㷢������ԭ��������һ��ͨ�����������.
��������Щ��, �����㡸���ܡ�������ȥ....

HOLE
    ]) );
    set("exits", ([
    "southwest" : __DIR__"field1",
]));
    set("outdoors", "green");

	setup();
    //replace_program(ROOM);
}

void init()
{
    add_action("do_climb","climb");
}

string long_desc()
{
    string str;
    object ob;
    str = query("long.desc");
    ob = first_inventory(__DIR__"wall1");
    if (!ob) return str+"\n";
    else
    return sprintf("%s\n������%s��������������\n",
        str,(string)ob->name());
}

int do_climb(string str)
{
    object ob;
    if (!str) return notify_fail("������? ������?!?\n");
    if ((str != "wall") && (str != "up"))
        return notify_fail("��.... �㲻����������ȥ��.\n");
    ob = first_inventory(__DIR__"wall1");
    if (!ob) { // can climb
        write("�����������һ����, ��׼��λ, ������������...\n");
        tell_room(environment(this_player()),
        (string)this_player()->name()+"���������һ����, ��ʼ������.\n",
        ({this_object(), this_player()}) );
        this_player()->move(__DIR__"wall1");
        return 1;
    }
    else {
        return notify_fail(sprintf("��̧ͷ��ȥ, %s���ں�Ŭ����������... ��Ҫ����...\n",
                                    (string)ob->name()));
    }
}

