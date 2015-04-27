#ifndef SCENEGRAPH_HPP_
#define SCENEGRAPH_HPP_

#include "LinearTransformation.hpp"
#include "Object.hpp"

namespace fast {


class SceneGraphNode : public Object {
    FAST_OBJECT(SceneGraphNode)
    public:
        void setTransformation(LinearTransformation transformation);
        void setParent(SceneGraphNode::pointer parent);
        SceneGraphNode::pointer getParent() const;
        LinearTransformation getLinearTransformation() const;
        void reset();
        bool isDataNode() const;
        bool isRootNode() const;
    private:
        SceneGraphNode();

        SceneGraphNode::pointer mParent;
        bool mIsRootNode;
        LinearTransformation mTransformation;
};

class SpatialDataObject;

namespace SceneGraph {
    LinearTransformation getLinearTransformationBetweenNodes(SceneGraphNode::pointer nodeA, SceneGraphNode::pointer nodeB);
    LinearTransformation getLinearTransformationFromNode(SceneGraphNode::pointer node);
    LinearTransformation getLinearTransformationFromData(SharedPointer<SpatialDataObject> node);
    void setParentNode(SharedPointer<SpatialDataObject> child, SharedPointer<SpatialDataObject> parent);
    SceneGraphNode::pointer insertParentNodeToData(SharedPointer<SpatialDataObject> child, LinearTransformation transform);
    SceneGraphNode::pointer insertParentNodeToNode(SceneGraphNode::pointer child, LinearTransformation transform);
};

} // end namespace fast



#endif /* SCENEGRAPH_HPP_ */
