// tao_first.c

inherit NPC;

void create()
{
        set_name("��ʬ����", ({ "trainer" }) );
        set("nickname", "��ʬ����");
        set("gender", "����");
        set("age", 27);
        set("long",
                
"��ʬ�������ּɵĵ��ӣ���һ���ɫ�ĵ���\n"
);
        set("combat_exp", 1400);
        set("score", 200);

        set("class", "taoist");

        set("str", 20);
        set("int", 30);
        set("cor", 20);
        set("cps", 30);
        set("spi", 30);

        set("force", 100);
        set("max_force", 100);
        set("force_factor", 5);

        set("atman", 100);
        set("max_atman", 100);

        set("mana", 200);
        set("max_mana", 200);
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
                "��ʬ����˵������ҿ����éɽ�ɰ�! \n",
                (:random_move :)        
        }) ); 

        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
                (: command("cast manimate on corpse") :),
                (: command("cast animate on corpse") :),         
        }) );

        create_family("éɽ��", 6, "����");

        set_skill("literate", 10);
        set_skill("magic", 20);
        set_skill("force", 20);
        set_skill("spells", 20);
        set_skill("scratching", 20);
        set_skill("unarmed", 20);
        set_skill("sword", 20);
        set_skill("parry", 20);
        set_skill("dodge", 20);
        set_skill("gouyee", 20);

        set_skill("taoism", 20);
        set_skill("necromancy", 20);    

        map_skill("spells", "necromancy");

        set_temp("apply/dodge", 20);
        set_temp("apply/armor", 20);

        setup();

        carry_object("/obj/example/sword")->wield();
        carry_object(__DIR__"obj/magic_book");
        carry_object(__DIR__"obj/spells_book");
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
 
