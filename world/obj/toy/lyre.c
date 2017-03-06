// lyre.c

#include <ansi.h>

inherit ITEM;

mapping music = ([
	"maiden lake": ({
		"$N�����������ȣ�������ˮһ�� ....\n",
		0, 0,
		"����Խ��Խ������ɽȪ�Ӱ��ɸߵ�ɽ�ڳ伤���� ....\n",
		"ˮ���Ľ���ɽ���ϵ���ľ��Ϊ�����ɶ��������� ....\n",
		0,
		"ɽȪ�����ڶ��͵�����б��������ľ����ڸ�\��һ�е����� ....\n",
		0, 0,
		"��Ȼ����������һ���������ͻ�����������ʼ��һ��ƽ�������ĸо� ...\n",
		0,
		"���������һƬˮ���л�������һ�����������ĺ��� ...\n",
		0,
		"������һƬ����ɫ�Ĳݵأ��þ�����ʫ�� ...\n",
		0,
		"$N�����������͵��������� ...\n"
	}),
]);

int play_lyre(object me, mixed *melody, int phase);

void create()
{
	set_name("��β��", ({ "lyre" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����ɫ�Ľ�β�٣��������൱����\n");
		set("value", 1300);
		set("weight", 8000);
	}
}

void init()
{
	add_action("do_play", "play");
}

int do_play(string arg)
{
	string name, instrument;

	if( !arg || sscanf(arg, "%s with %s", name, instrument )!= 2 )
		return notify_fail("ָ���ʽ��play <��Ŀ> with <����>\n");

	if( !id(instrument) ) return 0;
	message_vision("$Nȡ��һ�߽�β�٣���ϥ����������������\n", this_player());
	this_player()->start_busy( (: play_lyre, this_player(), music[name], 0 :), 1 );
	return 1;
}

int play_lyre(object me, mixed *melody, int phase)
{
	if( phase >= sizeof(melody) ) return 0;

	if( stringp(melody[phase]) )
		message_vision( HIG + melody[phase] + NOR, me);
	else if( functionp(melody[phase]) )
		evaluate(melody[phase], me);
	me->start_busy( (: play_lyre, me, melody, phase+1 :), 1);

	return 1;
}
