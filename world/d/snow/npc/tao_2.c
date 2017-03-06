// tao_2.c

inherit NPC;

void create()
{
        set_name("��ʬ����", ({ "tfighter" }) );
        set("nickname", "��ʬ����");
        set("gender", "����");
        set("age", 32);
        set("long",
                
"��ʬ������éɽ�ɵĻ�������һ���ɫ�ĵ���\n"
);
        set("combat_exp", 2000);
        set("score", 200);

        set("class", "taoist");

        set("str", 20);
        set("int", 30);
        set("cor", 20);
        set("cps", 30);
        set("spi", 30);
        set("pursuer", 1);

        set("force", 150);
        set("max_force", 150);
        set("force_factor", 5);

        set("atman", 150);
        set("max_atman", 150);

        set("mana", 300);
        set("max_mana", 300);
        set("mana_factor", 5);

        set("inquiry", ([
                "�����ķ�": 
"�����ķ�����éɽ��Ϊ�Կ�аħ����������ڹ��ķ���\n",
                "éɽ��": 
"��éɽ��������ʦ��ɽ�������������������Խ�����ħΪ���Ρ�\n"
        ]) );
        set("chat_chance", 25);
        set("chat_msg", ({
                "��ʬ����˵��������éɽ��ʵ����ǿ��˭���۸����ǣ�\n",
                "��ʬ��������˵����С���Ұ����ɽ�ʬ! \n",
                "��ʬ������������һ���䣬�㲻��ë���Ȼ����...\n",
                (:random_move :)        
        }) ); 

        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: command("������ң�׷�����ĺ����Ҷ�Ҫɱ���㣡") :),
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
                (: command("cast animate on corpse") :),
                (:command("cast animate on corpse") :),         
        }) );

        create_family("éɽ��", 6, "����");

        set_skill("literate", 10);
        set_skill("magic", 30);
        set_skill("force", 30);
        set_skill("spells", 30);
        set_skill("scratching", 30);
        set_skill("unarmed", 30);
        set_skill("sword", 30);
        set_skill("parry", 30);
        set_skill("dodge", 30);
        set_skill("gouyee", 30);

        set_skill("taoism", 30);
        set_skill("necromancy", 30);    

        map_skill("spells", "necromancy");

        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);

        setup();

        carry_object("/obj/example/sword")->wield();
//        carry_object(__DIR__"obj/taoism_book");
//        carry_object(__DIR__"obj/s_spells_book");
        add_money("gold", 3);

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
 
