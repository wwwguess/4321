// Mon  08-21-95

inherit ITEM;

void create()
{
	set_name("����", ({"rope"}) );
	if (clonep())
		set_default_object(__FILE__);
	else {
	set("unit","��");
	set("long", @LONG
����һ��������. ������������ϵ�(hang).

LONG
	);
	set("material","linen");
	set("value",5);
	set_weight(3000);
	}
}

void init()
{
    add_action("hang_self", "hang");
}

int hang_self(string str)
{
    // do we pass any argument?
    if (!str)
        return notify_fail("��... ���ϵ���? hang <name> ��... \n");
    // check if we are doing this indoor
    if (environment(this_player())->query("outdoors"))
        return notify_fail("���Ĵ�����, ʵ���Ҳ����ط�������˵...\n");
    // are we hanging ourselves? :-)
    if (((string)this_player()->query("id") != str) && (str != "self"))
        return notify_fail("��... �ϵ����Լ�����, �벻Ҫ����...\n");
    // if we get to here, we are ready..
    tell_room(environment(this_player()), (string)this_player()->name()+
    "̾��һ����, �ܿ϶��ذ��������ڲ�����.....\n",
    ({this_object(), this_player()}) );
    tell_object(this_player(), "�������һ�˹Һ�, ��һ����������һ��.....\n");
    this_player()->die();
    return 1;
}

