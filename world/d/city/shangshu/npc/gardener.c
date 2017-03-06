// gardener
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����", ({ "gardener" }) );
	set("gender", "����");
	set("age", 55);
        set("long",
		"һ������ʵʵ�������ֵַ�ׯ԰����������ķ�˪����\n"
		"�����Ķ�ͷ��������������û��������ע���������Ҳ\n"
		"����ĬĬ���ڻ�԰�﹤����\n"
                );

        set("attitude", "peaceful");

        set("combat_exp", 500000);

        set("str", 25);
        set("int", 27);
        set("cor", 23);
        set("cps", 28);
        set("spi", 30);

        set("force", 1800);
        set("max_force", 900);
        set("force_factor", 25);

        set("atman", 1200);
        set("max_atman", 1200);

        set("mana", 3500);
        set("max_mana", 1800);
        set("mana_factor", 4);

        set("inquiry", ([
                "éɽ��": 	"�����ҵ�ʦ�š�\n",
		"�ּ�":		"�ּɣ�����������ʦ�֣��þ�û�������ˡ�\n",
		"���峾":	"ʲô���峾�����ˣ�\n"
        ]) );

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
        }) );

        set_skill("literate", 100);
        set_skill("magic", 40);
        set_skill("force", 30);
        set_skill("spells", 90);
        set_skill("scratching", 90);
        set_skill("unarmed", 30);
        set_skill("sword", 40);
        set_skill("parry", 40);
        set_skill("dodge", 40);
        set_skill("gouyee", 60);

        set_skill("taoism", 90);
        set_skill("necromancy", 90);

        map_skill("spells", "necromancy");
	map_skill("sword", "scratching");
	map_skill("parry", "scratching");
	map_skill("force", "gouyee");

        setup();

        carry_object(__DIR__"obj/sword")->wield();
}
