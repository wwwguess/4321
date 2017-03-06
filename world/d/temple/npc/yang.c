// write by wawa 2/15/98

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��С��", ({ "yang xiaochuan", "yang" }) );
        set("nickname", "����");
        set("gender", "����");
        set("age", 22);
        set("long",
"��С����éɽ�ɵĻ�������һ���ɫ�ĵ���.���������\n"
);
        set("combat_exp", 800000);
        set("score", 18000);

        set("class", "taoist");

        set("int", 30);
        set("cps", 30);
        set("spi", 30);
        set("pursuer", 1);

        set("force", 1500);
       set("max_force", 1000);
        set("force_factor", 25);
        set("atman", 1000);
        set("max_atman", 1000);

        set("mana", 3000);
        set("max_mana", 1500);
        set("mana_factor", 5);

        set("inquiry", ([
                "�����ķ�":
"�����ķ�����éɽ��Ϊ�Կ�аħ����������ڹ��ķ���\n",
                "éɽ��":
"��éɽ��������ʦ��ɽ�������������������Խ�����ħΪ���Ρ�\n"
        ]) );
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
        }) );

        set_skill("magic", 80);
         set_skill("force", 80);
        set_skill("spells", 150);
        set_skill("unarmed", 50);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("gouyee", 100);

        map_skill("force", "gouyee");

        set_skill("taoism", 100);
        set_skill("necromancy", 120);

        map_skill("spells", "necromancy");

        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);

        setup();

        add_money("gold", 6);
        carry_object("/obj/weapon/longsword")->wield();
        carry_object(__DIR__"obj/robe2")->wear();
        carry_object(__DIR__"obj/hat")->wear();
        carry_object(__DIR__"obj/boots")->wear();

}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="éɽ��" ) {
                command("nod");
                command("say ���аɡ�");
                return 1;
        }
        command("say éɽ�ɲ��ͱ��ɵ��˹��С�");
        return 0;
}

