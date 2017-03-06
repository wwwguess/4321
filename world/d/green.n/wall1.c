// Mon  08-21-95

inherit ROOM;

int do_climb(string str);
string show_ring();

void create()
{
    set("short", "�ұ���");
    set("long", @LONG
��������ɽ��֮��, ���¿�ȥ�������������һ�ξ�����, ����
��ȥ, �ǿ�ͻ�����ʯҲ���Ǻ�Զ��. ������߶���һ������(ring).

LONG
	);
    set("item_desc", ([
    "ring" : (: show_ring :)
    ]) );
    set("outdoors", "green");

	setup();
    //replace_program(ROOM);
}

void init()
{
    reset();
    add_action("re_route_cmd","",1);
    add_action("do_climb", "climb");
}

int re_route_cmd(string str)
{
    string cmd;
    int i;
    string *invalid_cmds;
    cmd = query_verb();
    invalid_cmds = ({"enforce", "meditate", "practice", "study", "wield", "exercise", "learn", "scribe", "conjure", "enchant", "exert", "perform", "respirate", "drop"});
    i = member_array(cmd, invalid_cmds);
    if (i == -1) return 0;
    else write("����Ŀǰ�Ĵ�������, Ҫ������º���.\n");
    return 1;
}

int do_climb(string str)
{
    int chance;
    if (this_player()->query_temp("looked_ring")) chance = 10;
    else chance = random(10);
    if (!str) return notify_fail("������? ������?!?\n");
    if ((str != "up") && (str != "down"))
        return notify_fail("��.... ����û����������������.\n");
    write("�����������һ����, ��׼��λ, �����Ŀ�ʼ��...\n");
    if ((str == "up" ) && (chance >= 8)) {
        this_player()->move(__DIR__"top1");
        tell_room(environment(this_player()),
        (string)this_player()->name()+"�����������������.\n",
        this_player());
    return 1;
    }
    else {
        if ((str == "down" ) && (chance >= 8)) {
        this_player()->move(__DIR__"field2");
        tell_room(environment(this_player()),
        (string)this_player()->name()+"��С�ĵش�����������.\n",
        this_player());
        return 1;
        }
        else {
            write("һ��С��ûץ��.... ������ȥ... ˤ����ͷ���ۻ�.\n");
            this_player()->receive_damage("kee", 30);
            this_player()->move(__DIR__"field2");
            tell_room(environment(this_player()),
            "������һ���ҽ�, "+(string)this_player()->name()+"������ˤ��"+
            "����.\n",
            this_player());
        }
    }
    return 1;
}

string show_ring()
{
    this_player()->set_temp("looked_ring",1);
    return "һ�����������, Լ�����ư��, ���滹��һ�ضϵ�������, ��֪���Ǹ���\n"+
    "ù����������. ������������... ��������ð���հ�. С�ĵ������.\n";
}

