// Mon  08-21-95

inherit ROOM;

string long_desc();
string look_ring();
string look_drawing();

void create()
{
    seteuid(getuid());
    set("short", "ͻ����ʯ��");
    set("long", (: long_desc :));
    set("long.desc", @LONG
��վ��ɽ����һ��ͻ����ƽ̨��. ����ȥ���ǹ⻬���ұ�. ����
��ȥ����Կ����������Ӻ͵�·. �ұ�����һ����ֵ�ͼ��(drawing).
LONG
	);
    set("item_desc", ([
    "ring" : (: look_ring :),
    "drawing" : (: look_drawing :),
    ]) );
    set("outdoors", "green");

	setup();
    //replace_program(ROOM);
}

void reset()
{
    ::reset();
    delete_temp("has_rope");
}

void init()
{
    add_action("do_climb","climb");
    add_action("do_jump","jump");
    add_action("do_tie", "tie");
}

string long_desc()
{
    string str;
    str = query("long.desc");
    if (!query_temp("has_rope")) return str+"ƽ̨����һ������(ring).\n";
    else return str+"ƽ̨����һ������(ring). �������һ������.\n";
}

int do_climb(string str)
{
    if (!str) return notify_fail("������? ������?!?\n");
    if (!query_temp("has_rope"))
        return notify_fail("��.... û�����ӵĻ�����(jump)��ȥû����.\n");
    if ((str != "rope") && (str != "down"))
        return notify_fail("��.... �㲻����������ȥ��.\n");
    write("�����������һ����, ��׼��λ, ��������������������...\n");
    tell_room(environment(this_player()),
    (string)this_player()->name()+"���������һ����, �������ӿ�ʼ������.\n",
    this_player());
    this_player()->move(__DIR__"field2");
    tell_room(__DIR__"wall1",
    (string)this_player()->name()+"�������Ӵ����Ա߾���, ��ϧ�㹹��������.\n",
    this_player());
    tell_room(environment(this_player()),
    (string)this_player()->name()+"������������.\n",
    this_player());
    return 1;
}

int do_jump(string str)
{
    object ob;
    ob = this_player();
    if (!str) return 0;
    if (str != "down") return 0;
    tell_room(environment(ob), (string)ob->name()+"����������.\n", ob);
    write("���������һ����, ����������.\n");
    if ((int)ob->query("force") >= 300) {
    ob->move(__DIR__"field2");
    tell_room(environment(ob), (string)ob->name()+"��������������.\n", ob);
    }
    else {
    write("��Ȼ����һ������������....\n");
    ob->move(__DIR__"field2");
    write("��! ��һ��, ͷ������.\n");
    ob->unconcious();
    tell_room(environment(ob), "��! ��һ��, һ����������������.\n", ob);
    }
    tell_room(__DIR__"wall1","һ����Ӱ�������Էɹ�.\n");
    return 1;
}

string look_ring()
{
    if (this_player()->query_temp("looked_ring"))
    return "һ�����������, ��ſ��԰�(tie)���Ӱ�.\n";
    else return "һ�����������.\n";
}

string look_drawing()
{
    this_player()->set_temp("looked_shape",1);
    return (@SHAPE
    �� ����      ����
     ������������������ <- W
     ������������������
     ������������������ <- 57
     ������������������             ��
     ���������������������������������� <- 181
     ����������������������������������
                  ^67
SHAPE
    );
}

int do_tie(string str)
{
    object ob;
    if (!str) return notify_fail("��ɶ?\n");
    if (str != "rope") return notify_fail("�㻹��Ҫ��ɶ?\n");
    ob = present("rope",this_player());
    if (!ob) return notify_fail("��û������...\n");
    destruct(ob);
    write("��С�ĵؽ����Ӱ���������.\n");
    tell_room(environment(this_player()),
    (string)this_player()->name()+"�����Ӱ���������.\n",
    this_player());
    set_temp("has_rope",1);
    return 1;
}

