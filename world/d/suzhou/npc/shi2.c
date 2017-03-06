//NPC: /d/suzhou/npc/shi2.c
// by dwolf
//97.11.4

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("ʷ�ز�", ({"shi shoucai", "shi"}));
	set("title", HIM "Ǯׯ" NOR + YEL "�ϰ�" NOR);
	set("nickname", MAG "��" NOR + BLK "����" NOR);
	set("gender", "����");
	set("age", 40);

	set("str", 22);
	set("int", 24);
	set("dex", 28);
	set("con", 28);

	set("kee", 500); 
	set("max_kee", 500);
	set("gin", 150);
	set("max_gin", 150);
	set("shen", 1);

	set("combat_exp", 100000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set("chat_chance", 2);
	set("chat_msg", ({
	HIW"ʷ�زƽ�����˵�����������Ѿ��м��������ʷ����ȫ������˵�ǵ�һ�ҡ�\n"NOR,
 	HIW"ʷ�زƺǺ�Ц�����ڱ����Ǯ����Ϣ��ȡǮ��ʮ��֮һ�����ѣ��͹������Ű�ɡ�\n"NOR
	}));
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 45);

	setup();
	add_money("gold", 3);
}
