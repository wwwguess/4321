// Mon  08-21-95

inherit ROOM;

string look_drawing();

void create()
{
	set("short", "�峤�ļ�");
	set("long", @LONG
����һ�俴�����е㲻һ������լ�����ӵ�������һ��ʯ�Ƶ�¯�ӣ�
��������һ�ѻ����ܵĻ��������յ�������ƵĹ�����ǽ�Ϲ�������
�ֻ� (drawing)��һ�߻�����һ��ľ�Ƶ���ܣ��������������һЩ�ɵ�
�����پɵ��顣¯�ӵ��Ա߰���һ���ֹ�������ʯ�Σ������������Ҫ��
λ�á�
 
LONG
	);
    set("item_desc", ([
    "drawing" : (: look_drawing :),
    ]) );

    set("exits", ([
    "north" : __DIR__"field0",
]));

    set("objects", ([
    __DIR__"npc/oldman2" : 1,
	]) );

	setup();
}

string look_drawing()
{
    string str;
    str = "������������ͨͨ��ɽˮ��... ûɶ�ر��.... ����... ����һ����ô��Ҳ����ɽˮ˵...\n";
    if (this_player()->query_temp("looked_shape")) {
        this_player()->set_temp("looked_drawing",1);
        return str+"��ע�⵽�����������ɽ���Ͽ����ĺ���. ������һ���ʲݵ�ǩ��,\n"+
                   "��ֻ�ֱܷ�����м�������ŵĶ���.. Nolen...\n";
    }
    else return str+"���滭��һЩ�����й��ɵ�����... ������һ��Ҳ������.\n";
}

