
inherit NPC;

void create()
{
     set_name("Сɳ��", ({"bonze"}));
     set("gender", "����");
     set("class", "bonze");
     set("age",15);
     set("long","һ��������а��С����, һ��Բ����������ɰ���С��ͷ, ���˿���\n"
                "��ʮ�ֵ�ϲ������������Ϊ�͵��������͡�\n");
     set("combat_exp",800);
     set("attitude", "friendly");

     set("max_force", 400);
     set("force", 600);
     set("force_factor", 1);

     set_skill("force",30);
     set_skill("unarmed",20);
     set_skill("dodge",25);
     set_skill("buddhism",50);
     set_skill("lotusforce",30);
     
     map_skill("force", "lotusforce");
     
     setup();

     carry_object(__DIR__"obj/cloth")->wear();
     carry_object(__DIR__"obj/shoe")->wear();
}

int accept_fight(object me)
{
     command("say ʦ��! ������!!  ��....��Ҫ����..:( \n");
     return 0;
}
